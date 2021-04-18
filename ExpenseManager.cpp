#include "ExpenseManager.h"

Expense ExpenseManager::addExpense()
{
     system("cls");
    cout << " >>> DODAJ KOSZT <<<" << endl << endl;
    Expense expense = addExpenseData();

    expenses.push_back(expense);
    if(fileWithExpenses.saveExpenseToFile(expense))
    {
        cout<<"Dochod zostal dodany."<<endl;
    }
    else
        cout<<"Blad. Nie udalo sie dodac nowego dochodu do pliku." <<endl;
    system("pause");
}

Expense ExpenseManager::addExpenseData()
{
    Expense expense;
    char choice;
    string date="", expenseCategory="", value="";
    int dateOfExpense=0;
    double expenseValue=0;

    cout<<"Czy chcesz dodac wydatek z data dnia dzisiejszego?"<<endl;
    cout<<" 1. TAK"<<endl;
    cout<<" 2. NIE"<<endl;
    cin>>choice;

    switch (choice)
    {
    case '1':

        date=OperationsOnDates::todaysDate();
        break;
    case '2':
        cout<<"Podaj date w formacie: rrrr-mm-dd"<<endl;//mo¿e mo¿na wymusiæ wpisanie daty w odpowiednim formacie
        date=AuxiliartMethods:: loadLine();
        break;
    }
    if (OperationsOnDates::checkTheCorrectnessOfTheDate(date))
    {
        dateOfExpense=AuxiliartMethods::conversionStringForInt(date);

        cout<<dateOfExpense;

        cout<<"Podaj kategorie wydatku"<<endl;
        expenseCategory=AuxiliartMethods:: loadLine();
        cout<<"Podaj wartosc wydatku"<<endl;
        cin>>value;
        expenseValue=AuxiliartMethods::conversionStringForDouble(value);

        expense.setUserId(1);
        expense.setId(getExpenseId());
        expense.setDate(dateOfExpense);
        expense.setIncomeCategory (expenseCategory);
        expense.setValue(expenseValue);

    }
    else
        cout<<"data jest niepoprawna"<<endl;


    return expense;
}
int ExpenseManager :: getExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getId() + 1;
}
void ExpenseManager :: wypisz()
{

    for (int i=0; i<expenses.size(); i++)
    {
        cout<<expenses[i].getUserId()<<"  ";
        cout<<expenses[i].getId()<<"  ";
        cout<<expenses[i].getIncomeCategory()<<"  ";
        cout<<OperationsOnDates::changeTheDateFormat(expenses[i].getDate())<<"  ";
        cout<<expenses[i].getValue()<<endl;
    }
}
void ExpenseManager ::loadExpensesFromFile()
{
    expenses=fileWithExpenses.loadExpensesFromFile();
}
void ExpenseManager  :: balanceForTheCurrentMonth()
{
    string currentDate="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(currentDate);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(currentDate);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

   for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayExpenseData(*itr);
    }
    }
     if (expenses.empty())
         cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
}
void ExpenseManager ::displayExpenseData (Expense expense)
{
    cout<<endl<<expense.getId()<<"  kategoria dochodu:  "<< expense.getIncomeCategory()<<"  data:  "<< OperationsOnDates::changeTheDateFormat(expense.getDate())<<"  watrosc wydatku:  "<< expense.getValue();
}
void ExpenseManager  :: balanceForThePreviousMonth()
{
    string currentDate="", dateOfThePreviousMonth="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    dateOfThePreviousMonth=OperationsOnDates::SetTheDateBackOneMonth(currentDate);
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(dateOfThePreviousMonth);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(dateOfThePreviousMonth);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

   for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayExpenseData(*itr);
    }
    }
}
void ExpenseManager  ::expenseBalanceForTheSelectedPeriod()
{
    string startingDateOfTheBalance="", endDateOfTheBalance="";
    int startingDate=0, endDate=0;
    cout<<"Podaj date, od ktorej chcesz wyswietlic bilans"<<endl;
    cin>>startingDateOfTheBalance;
    if (OperationsOnDates::checkTheCorrectnessOfTheDate(startingDateOfTheBalance))
    {
        cout<<"Podaj date, do ktorej chcesz wyswietlic bilans"<<endl;
        cin>>endDateOfTheBalance;
         if (OperationsOnDates::checkTheCorrectnessOfTheDate(endDateOfTheBalance))
    {
        system ("cls");
        cout<<"WYDATKI DLA PRZEDZIALU CZASU OD "<< startingDateOfTheBalance<< "DO "<< endDateOfTheBalance<<endl;
        startingDate=AuxiliartMethods::conversionStringForInt(startingDateOfTheBalance);
        endDate=AuxiliartMethods::conversionStringForInt(endDateOfTheBalance);
        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=startingDate && itr->getDate()<=endDate){
                displayExpenseData(*itr);
    }
    }
    }
    }
}
