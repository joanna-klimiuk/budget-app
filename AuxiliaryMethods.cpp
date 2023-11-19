#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertDoubleToString(double number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::loadLine()
{
    cin.sync();
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadChar()
{
    string input = "";
    char output  = {0};
    cin.sync();

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            output = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return output;
}

double AuxiliaryMethods::loadAmount()
{
    string input = "";
    double amount = 0;

    while (true)
    {
        cin.sync();
        getline(cin, input);

        for (size_t i = 0; i < input.size(); i++)
        {
            if (input[i] == ',')
                input.replace(i, 1, ".");
        }

        stringstream myStream(input);
        if (myStream >> amount)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return amount;
}
