#include <iostream>
#include <cstdlib>
#include "PersonalBudget.h"
using namespace std;

int main()
{
    PersonalBudget personalBudget;

    char choiceFromTheMenu;
        while (true)
    {
        if (personalBudget.checkIfTheUserIsLoggedIn()==false)
        {
            choiceFromTheMenu = personalBudget.loginMenuOptions();

            switch (choiceFromTheMenu)
            {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }

      else
        {
            if (personalBudget.checkIfTheUserIsLoggedIn())
            {
                choiceFromTheMenu = personalBudget.userMenuOptions();

                switch (choiceFromTheMenu)
                {
                case '1':
                    personalBudget.addIncome();
                    break;
                case '2':
                    personalBudget.addExpense();
                    break;
                case '3':
                    personalBudget.balanceCurrentMonths();
                    break;
                case '4':
                    personalBudget.balanceOfThePreviousMonth();
                    break;
                case '5':
                    personalBudget.balanceSelectedPeriodOfTime();
                    break;
                case '6':
                    personalBudget.changePasswordOfLoggedInUsser();
                    break;
                case '9':
                    personalBudget.logout();
                    break;


            }
            }
        }

    }

    return 0;
    }
