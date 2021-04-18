#include"BudgetManager.h"

void BudgetManager::addIncome(){

incomeManager.addIncome();

}
void BudgetManager::addExpense(){

expenseManager.addExpense();
}
void BudgetManager::balanceCurrentMonths(){
    cout<<"DOCHODY BIERZACEGO MIESIACA: "<<endl;
incomeManager.balanceForTheCurrentMonth();

cout<<"WYDATKI BIERZACEGO MIESIACA: "<<endl;
expenseManager.balanceForTheCurrentMonth();
}
void  BudgetManager::balanceOfThePreviousMonth(){
    cout<<"DOCHODY POPRZEDNIEGO MIESIACA: "<<endl;
incomeManager.balanceForThePreviousMonth();
    cout<<"WYDATKI POPRZEDNIEGO MIESIACA: "<<endl;
expenseManager.balanceForThePreviousMonth();

}
void  BudgetManager::balanceSelectedPeriodOfTime(){

incomeManager.incomeBalanceForTheSelectedPeriod();

expenseManager.expenseBalanceForTheSelectedPeriod();
}
