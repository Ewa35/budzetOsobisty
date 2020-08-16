#include <iostream>
#include "User.h"
#include "UserManager.h"
#include "IncomeManager.h"
using namespace std;


int main()
{

   IncomeManager in;
    in.addIncome();

    return 0;
}





/*int main()
{

    UserManager userManager;
    //userManager.userRegistration();
    userManager.loadUsersFromFile();
    userManager.loginUser();

   // userManager.wypisz();
   userManager.changePasswordOfLoggedInUser();


    return 0;
}*/
















/*int main()
{
    User user;
    user.setId(1);
    user.setName("Ewa");
    user.setLastName("Kwiecien");
    user.setLogin("123ewa");
    user.setPassword("1220");

    cout << user.getId() << endl;
    cout << user.getName() << endl;
    cout << user.getLastName() << endl;
    cout << user.getLogin() << endl;
    cout << user.getPassword() << endl;
    return 0;
}*/
