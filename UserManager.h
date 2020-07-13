#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "User.h"
#include "FileWithUsers.h"
using namespace std;

class UserManager{

vector <User> users;
FileWithUsers fileWithUsers;

public:
void userRegistration();
User giveDataNewUser();
int downloadNewUserId();
void  wypisz();








};
#endif
