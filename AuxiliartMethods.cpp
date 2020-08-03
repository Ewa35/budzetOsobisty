#include "AuxiliartMethods.h"

string AuxiliartMethods:: loadLine()
{
    string stringOfCharacters = "";
    cin.sync();
    getline(cin, stringOfCharacters);
    return stringOfCharacters;

}
