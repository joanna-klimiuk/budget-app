#include "TransactionFile.h"

void TransactionFile::addTransactionToTheFile(Transaction transaction)
{
    bool bSuccess = xml.Load(FILE_NAME);

    if(!bSuccess)
    {
        xml.AddElem("Transactions"); // dodaj element "Transactions"
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Transaction");
    xml.IntoElem();
    xml.AddElem("UserId", transaction.getUserId());
    xml.AddElem("Type", transaction.getTransactionType());
    xml.AddElem("TransactionId", transaction.getTransactionId());
    xml.AddElem("Date", transaction.getTransactionDate());
    xml.AddElem("Amount", AuxiliaryMethods::convertDoubleToString(transaction.getAmount()));
    xml.AddElem("Item", transaction.getItem());

    xml.Save(FILE_NAME);

    lastTransactionId++;
}

vector <Transaction> TransactionFile::loadTransactionsFromFile(int userId)
{
    Transaction transaction;
    vector <Transaction> transactions;

    bool bSuccess = xml.Load(FILE_NAME);

    xml.ResetPos();
    xml.FindElem(); //jestesmy w Transactions
    xml.IntoElem(); //Wchodzimy wglab Transactions

    if (bSuccess)
    {
        while(xml.FindElem("Transaction"))
        {
            xml.IntoElem();
            xml.FindElem("UserId");
            if (userId != atoi(xml.GetData().c_str()))
                xml.OutOfElem();

            else
            {
                xml.FindElem("Type");
                transaction.setTransactionType(xml.GetData());
                xml.FindElem("TransactionId");
                lastTransactionId = AuxiliaryMethods::convertStringToInt(xml.GetData());
                transaction.setTransactionId(lastTransactionId);
                xml.FindElem("Date");
                transaction.setTransactionDate(AuxiliaryMethods::convertStringToInt(xml.GetData()));
                xml.FindElem("Amount");
                transaction.setAmount(atof(xml.GetData().c_str()));
                xml.FindElem("Item");
                transaction.setItem(xml.GetData());
                xml.OutOfElem();
                transactions.push_back(transaction);
            }
        }
    }
        return transactions;
}

int TransactionFile::getLastTransactionId()
{
    return lastTransactionId;
}
