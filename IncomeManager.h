#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Income.h"
#include "OperationsOnDates.h"
#include "AuxiliartMethods.h"
#include "FileWithIncomes.h"
using namespace std;

class IncomeManager{

FileWithIncomes fileWithIncomes;
vector<Income> incomes;
Income addIncomeData();

int  getIncomeId();
void  wypisz();
void displayIncomeData (Income income);
string SetTheDateBackOneMonth(string date);
string SetTheDateBackOneYear(string date);

public:
Income addIncome();
void loadIncomesFromFile();
void balanceForTheCurrentMonth();
void  balanceForThePreviousMonth();
void incomeBalanceForTheSelectedPeriod();


struct before
{
    inline bool operator() ( Income& struct1,  Income& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
};



};
#endif
