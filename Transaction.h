#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int userId;
    int transactionId;
    int transactionDate;
    double amount;
    string item;
    string transactionType;

public:
    int getUserId();
    int getTransactionId();
    int getTransactionDate();
    double getAmount();
    string getItem();
    string getTransactionType();

    void setUserId(int userId);
    void setTransactionId(int transactionId);
    void setTransactionDate(int transactionDate);
    void setAmount(double amount);
    void setItem(string item);
    void setTransactionType(string transactionType);
};

#endif
