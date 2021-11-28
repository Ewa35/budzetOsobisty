#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliartMethods.h"
using namespace std;

class UserManager {

    vector <User> users;
    FileWithUsers fileWithUsers;
    int loggedUserId;
public:
    UserManager(string userFileName):fileWithUsers(userFileName) {
        loggedUserId=0;
        users=fileWithUsers.loadUsersFromFile();
    };
    void userRegistration();
    User giveDataNewUser();
    int downloadNewUserId();
    void loadUsersFromFile();
    void  wypisz();
    void loginUser();
    void changePasswordOfLoggedInUser();
    bool checkIfTheUserIsLoggedIn();
    int currentlyLoggedUserId();
    void logout();





};
#endif
