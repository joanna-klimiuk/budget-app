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

void FinancialApp::showTransactions()
{
    if (userMeneger.isUserLoggedIn())
    {
        budgetMeneger -> showTransactions();
    }
}

