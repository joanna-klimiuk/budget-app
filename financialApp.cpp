#include "financialApp.h"


void FinancialApp::userRegister()
{
    userMeneger.userRegister();
}

void FinancialApp::userLogIn()
{
    userMeneger.userLogIn();

    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger = new BudgetMeneger(TRANSACTION_FILE_NAME, userMeneger.getIdOfLoggedInUser());
    }
}

void FinancialApp::userLogOut()
{
    userMeneger.logOut();
    delete budgetMeneger;
    budgetMeneger = NULL;
}

bool FinancialApp::isUserLoggedIn()
{
    if (userMeneger.isUserLoggedIn())
        return true;

    else
        return false;
}

void FinancialApp::changePasswordOfLoggedInUser()
{
    userMeneger.changePassword();
}

void FinancialApp::addIncome()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> addIncome();
    }
}

void FinancialApp::addExpense()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> addExpense();
    }
}

void FinancialApp::showBalanceOfCurrentMonth()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> showBalanceOfCurrentMonth();
    }
}

void FinancialApp::showBalanceOfPreviousMonth()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> showBalanceOfPreviousMonth();
    }
}

void FinancialApp::showBalanceOfSelectedPeriod()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> showBalanceOfSelectedPeriod();
    }
}

char FinancialApp::selectOptionsFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    return choice;
}

char FinancialApp::selectOptionFromAppMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  APLIKACJI <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "8. Zmien haslo" << endl;
    cout << "9. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadChar();

    return choice;
}

