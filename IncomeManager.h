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
Income addIncomeData(int userId);

int  getIncomeId();
void displayIncomeData (Income income);

public:

Income addIncome(int userId);
void loadIncomesFromFile(int userId);
void balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
void  balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
void incomeBalanceForTheSelectedPeriod(int startingDate, int endDate);


struct before
{
    inline bool operator() ( Income& struct1,  Income& struct2)
    {
        return (struct1.getDate() < struct2.getDate());
    }
};



};
#endif
