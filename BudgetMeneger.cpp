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

bool BudgetMeneger::compareDates (Transaction &transaction1, Transaction &transaction2)
{
    return (transaction1.getTransactionDate() <  transaction2.getTransactionDate());
}

void BudgetMeneger::showTransactions()
{
    int dateFrom, dateTo;
    int sumOfIncomes = 0;
    int sumOfExpenses = 0;
    int balance = 0;
    cout << "Podaj okres czasu:" << endl << "Od: ";
    dateFrom = Date::selectDate();

    cout << endl << "Do: ";
    dateTo = Date::selectDate();

    sort(incomes.begin(), incomes.end(), compareDates);
    sort(expenses.begin(), expenses.end(), compareDates);

    for(size_t i = 0; i < incomes.size(); i++)
    {
        if (incomes[i].getTransactionDate() <= dateTo && incomes[i].getTransactionDate() >= dateFrom)
        {
            displayTransaction(incomes[i]);
            sumOfIncomes += incomes[i].getAmount();
        }
    }

      for(size_t i = 0; i < expenses.size(); i++)
    {
        if (expenses[i].getTransactionDate() <= dateTo && expenses[i].getTransactionDate() >= dateFrom)
        {
            displayTransaction(expenses[i]);
            sumOfExpenses += expenses[i].getAmount();
        }
    }

    cout << "Saldo z prezdstawionego okresu: " << sumOfIncomes - sumOfExpenses << endl;
}

void BudgetMeneger::displayTransaction(Transaction transaction)
{
    cout << transaction.getTransactionDate() << " " << transaction.getAmount() << " zl " << transaction.getItem() << endl;
}

