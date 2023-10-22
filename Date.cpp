#include "Date.h"

int Date::getTodayDate()
{
    time_t today;
    tm *todayTm;
    int todayDateInt;

    time (&today);
    todayTm = localtime( & today);

    todayDateInt = (todayTm -> tm_year + 1900) *10000 + (todayTm -> tm_mon + 1) *100 + todayTm -> tm_mday;

    return todayDateInt;
}

int Date::selectDate()
{
    string stringDate = "0";

    cout << "Czy z dzisiejsza data? " << "tak: nacisnij 't'" << endl << "nie: nacisnij dowolny inny znak" << endl.

    if (AuxiliaryMethods::loadChar() == 't')
        getTodayDate();

    else
    {
        while(!isDateCorrect(stringDate))
        {
            cout << "Podaj date w formacie rrrr-mm-dd" << endl;
            stringDate = AuxiliaryMethods::loadLine()
        }
    }
}

bool Date::isDateCorrect(string stringDate)
{
    string yearString = "";
    string monthString = "";
    string dayString = "";
    int yearInt, monthInt, dayInt;

    //stringDate = "2022-8-5";

    for (int textPosition = 0; textPosition < 4; textPosition++)
    {
        yearString += stringDate[textPosition];
    }

    yearInt = atoi(yearString.c_str());

    if (yearInt < 2000 || yearInt >= getTodayDate() / 1000)
        return false;

    int textPosition = 5;
    while (stringDate[textPosition] != '-')
    {
        monthString += stringDate[i];
        textPosition++;
    }

    monthInt = atoi(monthString.c_str());

    if (monthInt < 1 || monthInt > 12)
        return false;

    textPosition++;
    while (textPosition < stringDate.size())
    {
        dayString += stringDate[textPosition];
        textPosition++;
    }

    dayInt = atoi(dayString.c_str());

    if(!isDayCorrect(dayInt, monthInt, yearInt))
        return false;

    else if (convertDateToNumber(dayInt, monthInt, yearInt) > getTodayDate())
        return false;

    else
        return true;
}

bool Date::isDayCorrect(int day, int month, int year)
{
    int maxDayNumber;

    if (month == 2 && isYearLeap(year) == true)
        maxDayNumber = 29;

    else if (month == 2 && isYearLeap(year) == false)
        maxDayNumber = 28;

    else if (month % 2 == 0)
        maxDayNumber = 30;

    else
        maxDayNumber = 31;

    if (day >= 1 && day <= maxDayNumber)
        return true;

    else
        return false;
}

bool Date::isYearLeap(int year)
{
    if(year % 400 == 0)
        return true;

    else if (year % 4 == 0 && year % 100 != 0)
        return true;

    else
        return false;
}

int Date::convertDateToNumber(int day, int month, int year)
{
    return year * 10000 + month * 100 + day;
}

