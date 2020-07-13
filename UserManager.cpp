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
