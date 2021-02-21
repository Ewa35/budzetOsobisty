#include "IncomeManager.h"

Income IncomeManager::addIncome()
{
     system("cls");
    cout << " >>> DODAJ DOCHOD <<<" << endl << endl;
    Income income = addIncomeData();

    incomes.push_back(income);
    if(fileWithIncomes.saveIncomeToFile(income))
    {
        cout<<"Dochod zostal dodany."<<endl;
    }
    else
        cout<<"Blad. Nie udalo sie dodac nowego dochodu do pliku." <<endl;
    system("pause");
}

Income IncomeManager::addIncomeData()
{
    Income income;
    char choice;
    string date="", incomeCategory="", value="";
    int dateOfIncome=0;
    double incomeValue=0;

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

        income.setUserId(1);
        income.setId(getIncomeId());
        income.setDate(dateOfIncome);
        income.setIncomeCategory (incomeCategory);
        income.setValue(incomeValue);

    }
    else
        cout<<"data jest niepoprawna"<<endl;


    return income;
}
int IncomeManager :: getIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getId() + 1;
}
void IncomeManager :: loadIncomesFromFile()
{
    incomes=fileWithIncomes.loadIncomesFromFile();
    sort( incomes.begin(), incomes.end(), before() );
    // wypisz();
}
void IncomeManager  :: wypisz()
{

    for (int i=0; i<incomes.size(); i++)
    {
        cout<<incomes[i].getUserId()<<"  ";
        cout<<incomes[i].getId()<<"  ";
        cout<<incomes[i].getIncomeCategory()<<"  ";
        cout<<OperationsOnDates::changeTheDateFormat(incomes[i].getDate())<<"  ";
        cout<<incomes[i].getValue()<<endl;
    }
}
void IncomeManager  :: balanceForTheCurrentMonth()
{
    string currentDate="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(currentDate);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(currentDate);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

   for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayIncomeData(*itr);
    }
    }
}


void IncomeManager  ::displayIncomeData (Income income)
{
    cout<<endl<<income.getId()<<"  kategoria dochodu:  "<< income.getIncomeCategory()<<"  data:  "<< OperationsOnDates::changeTheDateFormat(income.getDate())<<"  watrosc dochodu:  "<< income.getValue();
}
void IncomeManager  :: balanceForThePreviousMonth()
{
    string currentDate="", dateOfThePreviousMonth="", firstDayOfTheMonth="", lastDayOfTheMonth="";
    int integerFirstDayOfTheMonth=0, integerLastDayOfTheMonth=0;
    currentDate=OperationsOnDates::todaysDate();
    dateOfThePreviousMonth=OperationsOnDates::SetTheDateBackOneMonth(currentDate);
    firstDayOfTheMonth=OperationsOnDates::downloadFirstDayOfTheMonth(dateOfThePreviousMonth);
    lastDayOfTheMonth=OperationsOnDates::downloadLastDayOfTheMonth(dateOfThePreviousMonth);
    integerFirstDayOfTheMonth=AuxiliartMethods::conversionStringForInt(firstDayOfTheMonth);
    integerLastDayOfTheMonth=AuxiliartMethods::conversionStringForInt(lastDayOfTheMonth);

   for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=integerFirstDayOfTheMonth && itr->getDate()<=integerLastDayOfTheMonth){
                displayIncomeData(*itr);
    }
    }
}

void IncomeManager  ::incomeBalanceForTheSelectedPeriod()
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
        startingDate=AuxiliartMethods::conversionStringForInt(startingDateOfTheBalance);
        endDate=AuxiliartMethods::conversionStringForInt(endDateOfTheBalance);
        for (vector <Income> :: iterator itr = incomes.begin(); itr != incomes.end(); ++itr) {
           if (itr->getDate() >=startingDate && itr->getDate()<=endDate){
                displayIncomeData(*itr);
    }
    }
    }
    }
}
