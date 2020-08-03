#include "UserManager.h"

void UserManager:: userRegistration()
{
    User user = giveDataNewUser();
    users.push_back(user);
    fileWithUsers.addUsersToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager:: giveDataNewUser()
{
    User user;
    string name, lastName, login, password;
    user.setId(downloadNewUserId());
    cout<<"Podaj imie"<<endl;
    cin>>name;
    cout<<"Podaj nazwisko"<<endl;
    cin>>lastName;
    cout<<"Podaj login"<<endl;
    cin>>login;
    cout<<"Podaj haslo"<<endl;
    cin>>password;
    user.setName(name);
    user.setLastName(lastName);
    user.setLogin(login);
    user.setPassword(password);
    return user;
}

int UserManager :: downloadNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
void UserManager :: wypisz()
{
    for (int i=0; i<users.size(); i++)
    {
        cout<<users[i].getId()<<endl;
        cout<<users[i].getName()<<endl;
        cout<<users[i].getLastName()<<endl;
        cout<<users[i].getLogin()<<endl;
        cout<<users[i].getPassword()<<endl;
    }
}
void UserManager ::loadUsersFromFile()
{
    users=fileWithUsers.loadUsersFromFile();
    wypisz();
}
void UserManager ::loginUser()
{
    User user;
    int amountOfUsers=0;
    string userLogin = "", userPassword = "";

    cout << endl << "Podaj login: ";
    userLogin = AuxiliartMethods::loadLine();

    for (int i=0; i<users.size(); i++) {
        if (users[i].getLogin() == userLogin) {
                amountOfUsers++;
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                userPassword= AuxiliartMethods::loadLine();

                if (users[i].getPassword() == userPassword) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    loggedUserId=users[i].getId();
                    system("pause");
                    numberOfAttempts=0;
                }
                else if (numberOfAttempts==0 && loggedUserId==0) {
                    cout << "Wprowadzono 3 razy bledne haslo." << endl;
                    system("pause");
                    loggedUserId=0;
                }
            }
        }
    }
    if (amountOfUsers==0)
            {
                cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
                system("pause");
            }

}
void UserManager ::changePasswordOfLoggedInUser() {
        string  newPassword = "";
        string lineWithData="";
        cout << "Podaj nowe haslo: ";
        newPassword = AuxiliartMethods::loadLine();

        /*for (int i=0; i<users.size(); i++) {
            if (users[i].getId() == loggedUserId) {
                users[i].setPassword(newPassword);
                cout << "Haslo zostalo zmienione." << endl << endl;
                system("pause");
            }
        }*/
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
                 if (itr->getId() == loggedUserId)
                 {
                     itr->setPassword(newPassword);
                     cout << "Haslo zostalo zmienione." << endl << endl;
                    system("pause");
                    lineWithData=fileWithUsers.replaceUserDataForDataLinesSeparatedByVerticalLines(*itr);
                 }
        }



        fileWithUsers.saveTheNewPasswordInAFile(lineWithData,loggedUserId);
    }
