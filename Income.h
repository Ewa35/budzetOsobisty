#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{
 public:
 int userId;
 int id;
 string category;
  int date;
  double value;

public:
     Income (int userId=0, int id=0, string category="", int date=0, double value=0)
     {
         this->userId=userId;
         this->id=id;
         this->category=category;
         this->date=date;
         this->value=value;

     };


    void setUserId (int newUserId);
    void setId (int newId);
    void setIncomeCategory (string newIncomeCategory);
    void setDate (int newDate);
    void setValue (double newValue);

    int getUserId();
    int getId();
    string getIncomeCategory();
    int getDate();
    double getValue();


};
#endif
