#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <sstream>

#include "User.h"
#include "Markup.h"

using namespace std;
class FileWithUsers
{
    string replaceUserDataForDataLinesSeparatedByVerticalLines(User user);
    string conversionIntForString(int number);// zrobliæ klase metodu pomocnicze
    public:
    void addUsersToFile(User user);
};
#endif
