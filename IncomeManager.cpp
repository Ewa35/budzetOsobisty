#include "IncomeManager.h"

Income IncomeManager::addIncome()
{
     system("cls");
    cout << " >>> DODAJ DOCHOD <<<" << endl << endl;
    Income income = addIncomeData();

    incomes.push_back(income);
    if(fileWithIncomes.saveIncomeToFile(income))
    {
        cout<<"Nowy adresat zostal dodany."<<endl;
    }
    else
        cout<<"Blad. Nie udalo sie dodac nowego adresata do pliku." <<endl;
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
