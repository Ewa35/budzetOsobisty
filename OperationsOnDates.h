#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H

#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

class OperationsOnDates
{
   static void conversionCharONInt(string date, int &day, int &month, int &year);
    static int numberDaysOfTheMonth (int monthNumber, int year);
    public:
static string  todaysDate();
static bool checkTheCorrectnessOfTheDate(string date);
};
#endif
