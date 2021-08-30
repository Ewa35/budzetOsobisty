#include "ExpenseManager.h"

Expense ExpenseManager::addExpense(int userId)
{
     system("cls");
    cout << " >>> DODAJ KOSZT <<<" << endl << endl;
   Expense expense = addExpenseData( userId);

    expenses.push_back(expense);
    if(fileWithExpenses.saveExpenseToFile(expense))
    {
        cout<<"Wydatek zostal dodany."<<endl;
    }
    else
        cout<<"Blad. Nie udalo sie dodac nowego dochodu do pliku." <<endl;
        wypisz();
    system("pause");
}

Expense ExpenseManager::addExpenseData(int userId)
{
    Expense expense;
    char choice;
    string date="", expenseCategory="", value="";
    int dateOfExpense=0;
    double expenseValue=0;
     int expenseId=0;
    expenseId=getExpenseId();
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

        expense.setUserId(userId);
        expense.setId(expenseId);
        expense.setDate(dateOfExpense);
        expense.setIncomeCategory (expenseCategory);
        expense.setValue(expenseValue);

    }
    else
        cout<<"data jest niepoprawna"<<endl;


    return expense;
}
int ExpenseManager :: getExpenseId() {
    if (expenses.empty())
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
void ExpenseManager ::loadExpensesFromFile(int userId)
{
    expenses.clear();
    expenses=fileWithExpenses.loadExpensesFromFile(userId);
    sort( expenses.begin(), expenses.end(), before() );
}
void ExpenseManager  :: balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth)
{
    /*string currentDate="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0, numberOfHits=0;

    currentDate=OperationsOnDates::todaysDate();
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(currentDate);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(currentDate);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);*/

 double totalExpense=0;
 int numberOfHits=0;

   for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayExpenseData(*itr);
                totalExpense+=itr->getValue();
                numberOfHits++;
    }
    }
    if (numberOfHits==0)
         cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
    else
    {
    cout<<endl<<"Calkowita watrosc wydatkow w bierzacym miesiacu:   "<< totalExpense<<endl;
    }
    system("pause");
}
void ExpenseManager ::displayExpenseData (Expense expense)
{
    cout<<endl<<expense.getId()<<"  kategoria wydatku:  "<< expense.getIncomeCategory()<<"  data:  "<< OperationsOnDates::changeTheDateFormat(expense.getDate())<<"  watrosc wydatku:  "<< expense.getValue();
}
void ExpenseManager  :: balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth)
{
    /*string currentDate="", dateOfThePreviousMonth="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0, numberOfHits=0;
    double totalExpense=0;
    currentDate=OperationsOnDates::todaysDate();
    dateOfThePreviousMonth=OperationsOnDates::SetTheDateBackOneMonth(currentDate);
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(dateOfThePreviousMonth);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(dateOfThePreviousMonth);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);*/
    double totalExpense=0;
 int numberOfHits=0;

   for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayExpenseData(*itr);
                totalExpense+=itr->getValue();
                numberOfHits++;
    }
    if (numberOfHits==0)
         cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
    else
    {
    cout<<endl<<"Calkowita watrosc wydatkow w poprzednim miesiacu:   "<< totalExpense<<endl;
    }
    }
    system("pause");
}
void ExpenseManager  ::expenseBalanceForTheSelectedPeriod(int startingDate, int endDate)
{

    int  numberOfHits=0;
   double totalExpense=0;

        for (vector <Expense> :: iterator itr = expenses.begin(); itr != expenses.end(); ++itr) {
           if (itr->getDate() >=startingDate && itr->getDate()<=endDate){
                displayExpenseData(*itr);
                totalExpense+=itr->getValue();
              numberOfHits++;
    }
    }

   if (numberOfHits==0)
         cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
    else
    {
    cout<<endl<<"Calkowita watrosc wydatkow: "<< totalExpense<<endl;
    }

    system("pause");
}
