#ifndef OPERATIONSONDATES_H
#define OPERATIONSONDATES_H

#include <iostream>
#include <time.h>
#include <algorithm>
#include "AuxiliartMethods.h"
using namespace std;

class OperationsOnDates
{
   static void conversionCharONInt(string date, int &day, int &month, int &year);
    static int numberDaysOfTheMonth (int monthNumber, int year);
    public:
static string  todaysDate();
static bool checkTheCorrectnessOfTheDate(string date);
static  string changeTheDateFormat(int date);
static string getNumberDaysOfTheMonth (string date);
static string downloadFirstDayOfTheMonth(string currentDate);
static string downloadLastDayOfTheMonth(string currentDate);
static string SetTheDateBackOneMonth(string date);
static string SetTheDateBackOneYear(string date);
};
#endif
