#include <time.h>
#include <vector>
#include <iostream>

#include "AuxiliaryMethods.h"

class Date
{
    bool isDateCorrect(string dateString);
    bool isDayCorrect(int day, int month, int year);
    bool isYearLeap(int year);
    int convertStringDateToInt(string dateString);

public:
    int getTodayDate();
    int selectDate();
};
