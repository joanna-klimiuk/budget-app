#include "Transaction.h"

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getTransactionDate()
{
    return transactionDate;
}

double Transaction::getAmount()
{
    return amount;
}

string Transaction::getItem()
{
    return item;
}

string Transaction::getTransactionType()
{
    return transactionType;
}

void Transaction::setUserId(int userId)
{
    this -> userId = userId;
}

void Transaction::setTransactionId(int transactionId)
{
    this -> transactionId = transactionId;
}

void Transaction::setTransactionDate(int transactionDate)
{
    this -> transactionDate = transactionDate;
}

void Transaction::setAmount(double amount)
{
    this -> amount = amount;
}

void Transaction::setItem(string item)
{
    this -> item = item;
}

void Transaction::setTransactionType(string transactionType)
{
    this -> transactionType = transactionType;
}

bool Transaction::compareDates (Transaction &transaction1, Transaction &transaction2)
{
    return (transaction1.transactionDate <  transaction2.transactionDate);
}
