#include <iostream>

#include "UserMeneger.h"
#include "BudgetMeneger.h"

using namespace std;


class FinancialApp
{
    UserMeneger userMeneger;
    BudgetMeneger *budgetMeneger;
    const string FILE_WITH_EXPENSES;
    const string FILE_WITH_INCOMES;

public:
    FinancialApp(string UserFileName, string ExpensesFileName, string IncomesFileName)
        : userMeneger(UserFileName), FILE_WITH_EXPENSES(ExpensesFileName), FILE_WITH_INCOMES(IncomesFileName)
    {
        budgetMeneger = NULL;
    };

    ~FinancialApp()
    {
        delete budgetMeneger;
        budgetMeneger = NULL;
    }

  /*  void rejestracjaUzytkownika();
    void logowanieUzytkownika();
    void wypiszWszystkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogujUzytkownika();
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
