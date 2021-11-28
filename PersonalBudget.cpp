#include "PersonalBudget.h"

void PersonalBudget::userRegistration(){
    system ("cls");
    userManager.userRegistration();
}
void PersonalBudget::loginUser(){
    system ("cls");
userManager.loginUser();

 if (userManager.currentlyLoggedUserId()>0)
    {
        budgetManager= new BudgetManager (EXPENSES_FILE_NAME, INCOMES_FILE_NAME, userManager.currentlyLoggedUserId());
    }
}
void PersonalBudget::changePasswordOfLoggedInUsser(){
    system ("cls");
userManager.changePasswordOfLoggedInUser();
}
void PersonalBudget::addIncome(){
budgetManager->addIncome();
}
void PersonalBudget::addExpense(){
budgetManager->addExpense();
}
void PersonalBudget::balanceCurrentMonths(){
budgetManager->balanceCurrentMonths();
}
void PersonalBudget::balanceOfThePreviousMonth(){
budgetManager->balanceOfThePreviousMonth();
}
void PersonalBudget::balanceSelectedPeriodOfTime(){
budgetManager->balanceSelectedPeriodOfTime();
}
void PersonalBudget::logout()
{
userManager.logout();
}
bool PersonalBudget::checkIfTheUserIsLoggedIn()
{
if( userManager.checkIfTheUserIsLoggedIn())
    return true;
   else
    return false;
}

char PersonalBudget::loginMenuOptions()
{
    char choice='0';

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin>>choice;

    return choice;
}
char PersonalBudget::userMenuOptions ()
{
    char choice='0';
    system ("cls");
    cout << "    >>> MENU  U\276YTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj doch\242d" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Wy\230wietl bilans bierz\245cego miesi\245ca" << endl;
    cout << "4. Wy\230wietl bilans poprzedniego miesi\245ca" << endl;
    cout << "5. Wy\230wietl bilans dla wybranego okresu" << endl;
    cout << "6. Zmien haslo" <<endl;
    cout << "9. Wyloguj" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin.sync();
    cin>>choice;
    return choice;
}

