#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Expense.h"
#include "OperationsOnDates.h"
#include "AuxiliartMethods.h"
#include "FileWithExpenses.h"


using namespace std;

class ExpenseManager {
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses ;

    Expense addExpenseData(int userId, string date);
    int getExpenseId();
    void displayExpenseData (Expense expense);
    string selectDate();
public:
    ExpenseManager (string expensesFileName): fileWithExpenses(expensesFileName) {};
    void addExpense(int userId);
    void wypisz();
    void loadExpensesFromFile(int userId);
    void  balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
    void balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth);
    void expenseBalanceForTheSelectedPeriod(int startingDate, int endDate);
    struct before {
        inline bool operator() ( Expense& struct1,  Expense& struct2) {
            return (struct1.getDate() < struct2.getDate());
        }
    };

};
#endif
