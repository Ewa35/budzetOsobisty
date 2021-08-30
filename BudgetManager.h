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
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
   // vector <Income>incomes;
    //vector <Expense>expenses;

    int LOGGED_USER_ID;

public:
    BudgetManager ( int loggedUserId)
    :  LOGGED_USER_ID(loggedUserId) {
        //load();
        incomeManager.loadIncomesFromFile( LOGGED_USER_ID);
        expenseManager.loadExpensesFromFile( LOGGED_USER_ID);

    };
    void load();
    void addIncome();
    void addExpense();
    void balanceCurrentMonths();
    void  balanceOfThePreviousMonth();
    void  balanceSelectedPeriodOfTime();


};
#endif
