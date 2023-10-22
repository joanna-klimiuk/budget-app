#include <time.h>
#include <vector>

class Date
{
    bool isDateCorrect(string stringDate);
    bool isDayCorrect(int day, int month, int year);
    bool isYearLeap(int year);

    int convertDateToNumber(int day, int month, int y);

public:
    int getTodayDate();
    int selectDate();

};
