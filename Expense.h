#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include "Income.h"

using namespace std;

class Expense: public Income {
    int userId;
    int id;
    string category;
    int date;
    double value;

public:
    Expense (int userId=0, int id=0, string category="", int date=0, double value=0) {

        this->userId=userId;
        this->id=id;
        this->category=category;
        this->date=date;
        this->value=value;
    };
};
#endif
