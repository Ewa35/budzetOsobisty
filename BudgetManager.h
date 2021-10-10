#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class BudgetManager {

    IncomeManager incomeManager ;
    ExpenseManager expenseManager ;


    int LOGGED_USER_ID;

public:
    BudgetManager ( int loggedUserId)
    :  LOGGED_USER_ID(loggedUserId) {
        incomeManager.loadIncomesFromFile( LOGGED_USER_ID);
        expenseManager.loadExpensesFromFile( LOGGED_USER_ID);

    };
    void addIncome();
    void addExpense();
    void balanceCurrentMonths();
    void  balanceOfThePreviousMonth();
    void  balanceSelectedPeriodOfTime();


};
#endif
