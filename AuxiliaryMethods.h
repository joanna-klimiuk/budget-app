#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string loadLine();
    static char loadChar();
    static string convertIntToString(int number);
    static string convertDoubleToString(double number);
    static int convertStringToInt(string number);
    static double loadAmount();
};

#endif
