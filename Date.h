#ifndef DATE_H
#define DATE_H

#include <time.h>
#include <vector>
#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Date
{
    static bool isDateCorrect(string dateString);
    static bool isDayCorrect(int day, int month, int year);
    static bool isYearLeap(int year);

public:
    static int getTodayDate();
    static int selectDate();
    static int convertStringDateToInt(string dateString);
};

#endif
