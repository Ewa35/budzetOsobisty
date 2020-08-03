#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

int userId;
int id;
string incomeCategory;
int date;
double value;

public:
    void setUserId (int newUserId);
    void setId (int newId);
    void setIncomeCategory (string newIncomeCategory);
    void setDate (int newDate);
    void setValue (int newValue);

    int getUserId();
    int getId();
    string getIncomeCategory();
    int getDate();
    double getValue();

};
#endif
