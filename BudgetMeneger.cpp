#include "BudgetMeneger.h"

void BudgetMeneger::addIncome()
{
    Transaction transaction;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    transaction = enterTransactionDetails();
    transaction.setTransactionType("Income");

    incomes.push_back(transaction);
    transactionFile.addTransactionToTheFile(transaction);
    cout << "Dodano przychod do bazy" << endl;
    system("pause");
}

void BudgetMeneger::addExpense()
{
    Transaction transaction;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    transaction = enterTransactionDetails();
    transaction.setTransactionType("Expense");

    expenses.push_back(transaction);
    transactionFile.addTransactionToTheFile(transaction);
    cout << "Dodano wydatek do bazy" << endl;
    system("pause");
}

void BudgetMeneger::showBalanceOfCurrentMonth()
{
    int dateFrom, dateTo;

    dateTo = Date::getTodayDate();
    dateFrom = (dateTo / 100) * 100 + 1;

    showTransactions(dateFrom, dateTo);
    system("pause");
}

void BudgetMeneger::showBalanceOfPreviousMonth()
{
    int dateFrom, dateTo;

    dateTo = Date::getLastDayOfPreviousMonth();
    dateFrom = (dateTo / 100) * 100 + 1;

    showTransactions(dateFrom, dateTo);
    system("pause");
}

void BudgetMeneger::showBalanceOfSelectedPeriod()
{
    int dateFrom, dateTo;

    system("cls");
    cout << "Wybierz okres czasu." << endl << "Od: ";
    dateFrom = Date::selectDate();

    cout << endl << "do: ";
    dateTo = Date::selectDate();

    showTransactions(dateFrom, dateTo);
    system("pause");
}

Transaction BudgetMeneger::enterTransactionDetails()
{
    Transaction transaction;

    cout << "Czy z dzisiejsza data? " << "tak: nacisnij 't'" << endl << "nie: nacisnij dowolny inny znak" << endl;

    if (AuxiliaryMethods::loadChar() == 't')
    {
        transaction.setTransactionDate(Date::getTodayDate());
    }

    else
    {
        transaction.setTransactionDate(Date::selectDate());
    }

    transaction.setTransactionType("unknown");
    transaction.setUserId(USER_ID);
    transaction.setTransactionId(transactionFile.getLastTransactionId() + 1);

    cout << "Podaj nazwe: ";
    transaction.setItem(AuxiliaryMethods::loadLine());

    cout << "Podaj kwote: ";
    transaction.setAmount(AuxiliaryMethods::loadAmount());

    return transaction;
}

void BudgetMeneger::separateTransactionsIntoExpensesAndIncomes()
{
    for (auto transaction: transactions)
    {
        if (transaction.getTransactionType() == "Income")
        {
            incomes.push_back(transaction);
        }

        else if (transaction.getTransactionType() == "Expense")
        {
            expenses.push_back(transaction);
        }
    }
}

void BudgetMeneger::showTransactions(int dateFrom, int dateTo)
{
    double sumOfIncomes = 0;
    double sumOfExpenses = 0;

    sort(incomes.begin(), incomes.end(), Transaction::compareDates);
    sort(expenses.begin(), expenses.end(), Transaction::compareDates);

    cout << "Wplywy: " << endl;

    for(size_t i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getTransactionDate() <= dateTo && incomes[i].getTransactionDate() >= dateFrom)
        {
            displayTransaction(incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    cout << "Suma wplywow: " << sumOfIncomes << endl;

    cout << endl << "Wydatki: " << endl;

      for(size_t i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getTransactionDate() <= dateTo && expenses[i].getTransactionDate() >= dateFrom)
        {
            displayTransaction(expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    cout << "Suma wydatkow: " << sumOfExpenses << endl << endl;

    cout << "Saldo z przedstawionego okresu: " << sumOfIncomes - sumOfExpenses << endl;
}

void BudgetMeneger::displayTransaction(Transaction transaction)
{
    cout << Date::addDashesAndChangeDateToString(transaction.getTransactionDate()) << " " << transaction.getAmount() << " zl " << transaction.getItem() << endl;
}

