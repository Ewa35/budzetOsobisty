#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"
using namespace std;


class PersonalBudget{


UserManager userManager;
BudgetManager *budgetManager;
public:
    PersonalBudget()
    {
        budgetManager=NULL;
    };
    ~PersonalBudget()
    {
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

