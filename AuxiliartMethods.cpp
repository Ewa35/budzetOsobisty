#include "AuxiliartMethods.h"

string AuxiliartMethods:: loadLine()
{
    string stringOfCharacters = "";
    cin.sync();
    getline(cin, stringOfCharacters);
    return stringOfCharacters;

}
int AuxiliartMethods::conversionStringForInt(string number) {
    int numberInt;
    string bufforNumber;
    for (int i=0; i<number.length(); i++){
        if (number[i]!=45){
            bufforNumber+=number[i];

    }
    }
    istringstream iss(bufforNumber);
    iss >> numberInt;
    return numberInt;
}
string AuxiliartMethods::conversionDoubleForString (double value)
{
    stringstream str;
    str << fixed <<setprecision(3)<< value;
    string text = str.str();
    cout<<text;
    return text;
}
string  AuxiliartMethods:: conversionIntForString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
double AuxiliartMethods:: conversionStringForDouble(string value)
{
    string bufforValue;
    bufforValue=replaceCommaOnADot( value);
    double doubleValue;
    doubleValue = atof(bufforValue.c_str());
   return doubleValue;
}
string AuxiliartMethods:: replaceCommaOnADot(string value)
 {
     string buffor="";
     for (int i=0; i<value.length(); i++)
     {
         if (value[i]==44)
         {
             buffor+=".";
         }
         else
         {
             buffor+=value[i];
         }
     }
       return buffor;
 }
