#include "PersonalBudget.h"


void PersonalBudget::loginUser(){
userManager.loginUser();
}
void PersonalBudget::changePasswordOfLoggedInUsser(){
userManager.changePasswordOfLoggedInUser();
}
void PersonalBudget::addIncome(){
budgetManager.addIncome();
}
void PersonalBudget::addExpense(){
budgetManager.addExpense();
}
void PersonalBudget::balanceCurrentMonths(){
budgetManager.balanceCurrentMonths();
}
void PersonalBudget::balanceOfThePreviousMonth(){
budgetManager.balanceOfThePreviousMonth();
}
void PersonalBudget::balanceSelectedPeriodOfTime(){
budgetManager.balanceSelectedPeriodOfTime();
}
void PersonalBudget::logout(){}
