#include "IncomeManager.h"

Income IncomeManager::addIncome(int userId)
{
     system("cls");
    cout << " >>> DODAJ DOCHOD <<<" << endl << endl;
    Income income = addIncomeData(userId);

    incomes.push_back(income);
    if(fileWithIncomes.saveIncomeToFile(income))
    {
        cout<<"Dochod zostal dodany."<<endl;
    }
    else
        cout<<"Blad. Nie udalo sie dodac nowego dochodu do pliku." <<endl;
    system("pause");
}

Income IncomeManager::addIncomeData(int userId)
{
    Income income;
    char choice;
    string date="", incomeCategory="", value="";
    int dateOfIncome=0;
    double incomeValue=0;
    int incomeId=0;
    incomeId=getIncomeId();
    cout<<"Czy chcesz dodac dochod z data dnia dzisiejszego?"<<endl;
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
        dateOfIncome=AuxiliartMethods::conversionStringForInt(date);

        cout<<dateOfIncome;

        cout<<"Podaj kategorie dochodu"<<endl;
        incomeCategory=AuxiliartMethods:: loadLine();
        cout<<"Podaj wartosc przychodu"<<endl;
        cin>>value;
        incomeValue=AuxiliartMethods::conversionStringForDouble(value);

        income.setUserId(userId);
        income.setId(incomeId);
        income.setDate(dateOfIncome);
        income.setIncomeCategory (incomeCategory);
        income.setValue(incomeValue);

    }
    else
        cout<<"data jest niepoprawna"<<endl;


    return income;
}
int IncomeManager :: getIncomeId() {
    if (incomes.empty())
        return 1;
    else

        return incomes.back().getId()+1;
}
void IncomeManager :: loadIncomesFromFile(int userId)
{
  incomes.clear();
   incomes=fileWithIncomes.loadIncomesFromFile(userId);
   sort( incomes.begin(), incomes.end(), before() );


}

void IncomeManager  :: balanceForTheCurrentMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth)
{

    double totalIncome=0;
 int numberOfHits=0;

   for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayIncomeData(*itr);
                totalIncome+=itr->getValue();
                numberOfHits++;
    }
    }


    if (numberOfHits==0)
         cout<<" Brak dochodów w bierzacym miesiacu"<<endl;
    else
    {
        cout<<endl<<"Calkowita watrosc dochodow w bierzacym miesiacu:   "<< totalIncome<<endl;
    }

}


void IncomeManager  ::displayIncomeData (Income income)
{
    cout<<endl<<"  kategoria dochodu:  "<< income.getIncomeCategory()<<"  data:  "<< OperationsOnDates::changeTheDateFormat(income.getDate())<<"  watrosc dochodu:  "<< income.getValue();
}
void IncomeManager  :: balanceForThePreviousMonth(int integerFirstDayOfTheMonth, int integerLastDayOfTheMonth)
{

     double totalIncome=0;
 int numberOfHits=0;

   for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayIncomeData(*itr);
                totalIncome+=itr->getValue();
                numberOfHits++;
    }
    }
    if (numberOfHits==0)
         cout<<" Brak dochodów w bierzacym miesiacu"<<endl;
    else
    {
        cout<<endl<<"Calkowita watrosc dochodow w bierzacym miesiacu:   "<< totalIncome<<endl;
    }

}

void IncomeManager  ::incomeBalanceForTheSelectedPeriod(int startingDate, int endDate)
{

    int  numberOfHits=0;
    double totalIncome=0;

        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=startingDate && itr->getDate()<=endDate){
                displayIncomeData(*itr);
                numberOfHits++;
                totalIncome+=itr->getValue();
    }
        }
  if (numberOfHits==0)
         cout<<" Brak wydatkow w bierzacym miesiacu"<<endl;
    else
    {
    cout<<endl<<"Calkowita watrosc wydatkow: "<< totalIncome<<endl;
    }


}
