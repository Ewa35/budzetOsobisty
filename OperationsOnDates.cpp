#include "OperationsOnDates.h"

string OperationsOnDates::todaysDate() {
    time_t currentTime;
    tm *date;
    char todaysDate [11];
    time( & currentTime );
    date = localtime( & currentTime );
    strftime( todaysDate, 11, "%Y-%m-%d", date );
    return todaysDate;
}
bool OperationsOnDates::checkTheCorrectnessOfTheDate(string date) {
    int day, month, year;
    int currentDay, currentMonth, currentYear;
    int daysInAMonth;
    string currentDate;
    currentDate=todaysDate();
    conversionCharONInt( date,   day,   month,  year);
    conversionCharONInt(  currentDate,  currentDay,  currentMonth,  currentYear);
    if (year>=2000 && year<=currentYear) {
        if (month>=1 && month<=currentMonth) {
            daysInAMonth=numberDaysOfTheMonth( month,  year);
            if (day>=1 && day<= daysInAMonth) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void OperationsOnDates::conversionCharONInt(string date, int &day, int &month, int &year) {

    string dayBuffer, monthBuffer, yearBuffer;
    for (int i=0; i<10; i++) {
        if (i==0 || i<=3) {
            yearBuffer+=date[i];
        }
        if (i==5 || i==6) {
            monthBuffer+=date[i];
        }
        if (i==8 || i==9) {
            dayBuffer+=date[i];
        }
    }
    day = atoi(dayBuffer.c_str());
    month = atoi(monthBuffer.c_str());
    year = atoi(yearBuffer.c_str());
}

int OperationsOnDates::numberDaysOfTheMonth (int monthNumber, int year) {
    int numberDaysInAMonth=0;
    switch(monthNumber) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        numberDaysInAMonth=31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        numberDaysInAMonth=30;
        break;

    case 2: {

        if (((year%4 == 0) && (year%100 != 0)) || (year%400 == 0))
            numberDaysInAMonth=29;
        else
            numberDaysInAMonth=28;
    }
    break;
    default:
        cout<<"Niepoprawny numer miesiaca!";

    }
    return numberDaysInAMonth;
}
