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
    static bool isYearLeap(int year);
    static int maxDayNumber(int month, int year);
    static int convertStringDateToInt(string dateString);

public:
    static int getLastDayOfPreviousMonth();
    static int getTodayDate();
    static int selectDate();
    static string addDashesAndChangeDateToString(int dateInt);
};

#endif
