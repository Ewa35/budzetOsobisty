#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "IncomeManager.h"
#include "ExpenseManager.h"
using namespace std;

class BudgetManager {

IncomeManager incomeManager;
ExpenseManager expenseManager;
int LOGGED_USER_ID;

public:
    void addIncome();
    void addExpense();
    void balanceCurrentMonths();
void  balanceOfThePreviousMonth();
void  balanceSelectedPeriodOfTime();


};
#endif
