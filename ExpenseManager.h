#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "OperationsOnDates.h"
#include "AuxiliartMethods.h"
#include "FileWithExpenses.h"

using namespace std;

class ExpenseManager
{
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses ;

    Expense addExpenseData();
    int getExpenseId();
    void displayExpenseData (Expense expense);
public:
    Expense addExpense();
    void wypisz();
    void loadExpensesFromFile();
    void  balanceForTheCurrentMonth();
    void balanceForThePreviousMonth();
    void expenseBalanceForTheSelectedPeriod();
};
#endif
