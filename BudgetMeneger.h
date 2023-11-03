#include <iostream>
#include <vector>
#include <algorithm>

#include "Transaction.h"
#include "TransactionFile.h"
#include "AuxiliaryMethods.h"
#include "Date.h"

using namespace std;

class BudgetMeneger
{
    const int USER_ID;
    vector <Transaction> transactions;
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    TransactionFile transactionFile;

    Transaction enterTransactionDetails();
    void separateTransactionsIntoExpensesAndIncomes();
    bool compareDates (Transaction &transaction1, Transaction &transaction2);
    void displayTransaction(Transaction transaction);

public:
    BudgetMeneger(string TransactionFileName, int loggedInUserId)
        : USER_ID(loggedInUserId), transactionFile(TransactionFileName)
    {
        transactions = transactionFile.loadTransactionsFromFile(USER_ID);
        separateTransactionsIntoExpensesAndIncomes();
    };

    void addIncome();
    void addExpense();
    void showTransactions();
};
