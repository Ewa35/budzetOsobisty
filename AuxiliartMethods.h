#ifndef AUXILIARTMETHODS_H
#define AUXILIARTMETHODS_H

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>


using namespace std;

class AuxiliartMethods
{
   static string  replaceCommaOnADot(string value);
   public:

   static string loadLine();
   static int conversionStringForInt(string number);
   static string conversionDoubleForString (double value);
   static string  conversionIntForString(int number);
   static double conversionStringForDouble(string value);
};
#endif
