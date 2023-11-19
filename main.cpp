#include <iostream>
#include "financialApp.h"



using namespace std;

int main()
{
    char choice;

    FinancialApp financialApp("users.xml", "transactions.xml");

    while(true)
    {
        if(!financialApp.isUserLoggedIn())
        {
            choice = financialApp.selectOptionsFromMainMenu();

            switch(choice)
            {
            case '1':
                financialApp.userRegister();
                break;

            case '2':
                financialApp.userLogIn();
                break;

            case '9':
                exit(0);
                break;

            default:
                cout << endl << "Nie ma takiej opcji w MENU" << endl << endl;
                system("pause");
                break;
            }
        }

        else
        {
            choice = financialApp.selectOptionFromAppMenu();

            switch(choice)
            {
            case '1':
                financialApp.addIncome();
                break;

            case '2':
                financialApp.addExpense();
                break;

            case '3':
                financialApp.showBalanceOfCurrentMonth();
                break;

            case '4':
                financialApp.showBalanceOfPreviousMonth();
                break;

            case '5':
                financialApp.showBalanceOfSelectedPeriod();
                break;

            case '8':
                financialApp.changePasswordOfLoggedInUser();
                break;

            case '9':
                financialApp.userLogOut();
                break;

            default:
                cout << endl << "Nie ma takiej opcji w MENU" << endl << endl;
                system("pause");
                break;
            }
        }
    }

    return 0;
}
