#include"BudgetManager.h"


void BudgetManager::addIncome() {
    system ("cls");

    incomeManager.addIncome(LOGGED_USER_ID);

}
void BudgetManager::addExpense() {
    system ("cls");

    expenseManager.addExpense(LOGGED_USER_ID);
}
void BudgetManager::balanceCurrentMonths() {
    system ("cls");

    string currentDate="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(currentDate);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(currentDate);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

    cout<<endl<<"DOCHODY BIERZACEGO MIESIACA: "<<endl;
    incomeManager.balanceForTheCurrentMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
    cout<<endl<<endl<<" WYDATKI BIERZACEGO MIESIACA: "<<endl;
    expenseManager.balanceForTheCurrentMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
}
void  BudgetManager::balanceOfThePreviousMonth() {
    system ("cls");

    string currentDate="", dateOfThePreviousMonth="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    dateOfThePreviousMonth=OperationsOnDates::SetTheDateBackOneMonth(currentDate);
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(dateOfThePreviousMonth);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(dateOfThePreviousMonth);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);
    cout<<endl<<"DOCHODY POPRZEDNIEGO MIESIACA: "<<endl;
    incomeManager.balanceForThePreviousMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);
    cout<<endl<<"WYDATKI POPRZEDNIEGO MIESIACA: "<<endl;
    expenseManager.balanceForThePreviousMonth(integerFirstDayOfTheMonth, integerLastDayOfTheMonth);

}
void  BudgetManager::balanceSelectedPeriodOfTime() {
    system ("cls");

    string startingDateOfTheBalance="", endDateOfTheBalance="";
    int startingDate=0, endDate=0;

    cout<<"Podaj date, od ktorej chcesz wyswietlic bilans w formacie rrrr-mm-dd"<<endl;
    cin>>startingDateOfTheBalance;
    if (OperationsOnDates::checkTheCorrectnessOfTheDate(startingDateOfTheBalance)) {
        cout<<"Podaj date, do ktorej chcesz wyswietlic bilans w formacie rrrr-mm-dd"<<endl;
        cin>>endDateOfTheBalance;

        if (OperationsOnDates::checkTheCorrectnessOfTheDate(endDateOfTheBalance)) {
            system ("cls");
            startingDate=AuxiliartMethods::conversionStringForInt(startingDateOfTheBalance);
            endDate=AuxiliartMethods::conversionStringForInt(endDateOfTheBalance);
            cout<<endl<<"PRZYCHODY DLA PRZEDZIALU CZASU OD "<< startingDateOfTheBalance<< " DO "<< endDateOfTheBalance<<endl;
            incomeManager.incomeBalanceForTheSelectedPeriod(startingDate, endDate);
            cout<<endl<<endl<<"WYDATKI DLA PRZEDZIALU CZASU OD "<< startingDateOfTheBalance<< " DO "<< endDateOfTheBalance<<endl;
            expenseManager.expenseBalanceForTheSelectedPeriod(startingDate, endDate);

        }
    } else {
        cout<<"Podana data jest bledna. "<<endl;
        system ("pause");
        return ;
    }
}
