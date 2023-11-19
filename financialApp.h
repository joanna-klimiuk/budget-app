#include <iostream>

#include "UserMeneger.h"
#include "BudgetMeneger.h"

using namespace std;


class FinancialApp
{
    UserMeneger userMeneger;
    BudgetMeneger *budgetMeneger;
    const string TRANSACTION_FILE_NAME;

public:
    FinancialApp(string UserFileName, string TransactionFileName)
        : userMeneger(UserFileName), TRANSACTION_FILE_NAME(TransactionFileName)
    {
        budgetMeneger = NULL;
    };

    ~FinancialApp()
    {
        delete budgetMeneger;
        budgetMeneger = NULL;
    }

    void userRegister();
  //  void displayAllUsers();
    void userLogIn();
    bool isUserLoggedIn();
    void userLogOut();
    void changePasswordOfLoggedInUser();

    void addIncome();
    void addExpense();
    void showBalanceOfCurrentMonth();
    void showBalanceOfPreviousMonth();
    void showBalanceOfSelectedPeriod();

    char selectOptionsFromMainMenu();
    char selectOptionFromAppMenu();



  /*
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    bool czyUzytkownikJestZalogowany();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void usunAdresata();
    void edytujAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();*/
};
