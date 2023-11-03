#include <iostream>
#include "financialApp.h"



using namespace std;

int main()
{
    FinancialApp financialApp("users.xml", "transactions.xml");

    financialApp.userLogIn();
    financialApp.addIncome();
    financialApp.addIncome();
    financialApp.addExpense();
    financialApp.addExpense();

    financialApp.showTransactions();



    return 0;
}
