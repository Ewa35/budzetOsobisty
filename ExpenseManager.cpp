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
