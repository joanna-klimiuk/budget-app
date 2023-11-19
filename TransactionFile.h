#ifndef TRANSACTIONFILE_H
#define TRANSACTIONFILE_H

#include <iostream>
#include <vector>
#include "Markup.h"

#include <fstream>
#include <cstdlib>

#include "Transaction.h"
#include "AuxiliaryMethods.h"

using namespace std;


class TransactionFile
{
   const string FILE_NAME;
   CMarkup xml;
   int lastTransactionId = 0;

public:
    TransactionFile(string nameOfTransactionFile) : FILE_NAME(nameOfTransactionFile) {};
    int getLastTransactionId();
    void addTransactionToTheFile(Transaction transaction);
    vector <Transaction> loadTransactionsFromFile(int userID);

};

#endif
