#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H
#include <iostream>
#include "BudgetManager.h"
#include "UserManager.h"
using namespace std;


class PersonalBudget{


UserManager userManager;
BudgetManager budgetManager;

void loginUser();
void changePasswordOfLoggedInUsser();
void addIncome();
void addExpense();
void balanceCurrentMonths();
void balanceOfThePreviousMonth();
void balanceSelectedPeriodOfTime();
void logout();

};


#endif

