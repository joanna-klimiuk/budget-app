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
    static int convertStringToInt(string number);
  //  static int wczytajLiczbeCalkowita();
   // static string pobierzLiczbe(string tekst, int pozycjaZnaku);
   // static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
