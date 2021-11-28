#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"
using namespace std;


class PersonalBudget {


    UserManager userManager;
    BudgetManager *budgetManager;
    const string EXPENSES_FILE_NAME;
    const string INCOMES_FILE_NAME;

public:
    PersonalBudget(string userFileName, string expensesFileName, string incomesFileName )
        :userManager (userFileName), EXPENSES_FILE_NAME(expensesFileName), INCOMES_FILE_NAME(incomesFileName) {
        budgetManager=NULL;
    };
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager=NULL;
    };
    void userRegistration();
    void loginUser();
    void changePasswordOfLoggedInUsser();
    void addIncome();
    void addExpense();
    void balanceCurrentMonths();
    void balanceOfThePreviousMonth();
    void balanceSelectedPeriodOfTime();
    void logout();
    bool checkIfTheUserIsLoggedIn();
    char loginMenuOptions();
    char userMenuOptions ();

};


#endif

