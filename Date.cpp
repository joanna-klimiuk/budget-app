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
    string dateString = "";

    while(!isDateCorrect(dateString))
    {
        cout << "Podaj date w formacie rrrr-mm-dd" << endl;
        dateString = AuxiliaryMethods::loadLine();
    }
    return convertStringDateToInt(dateString);
}

int Date::convertStringDateToInt(string dateString)
{
    string DateWithoutDashes = dateString.erase(4,6) + dateString.substr(5,2) + dateString.substr(8,2);

    return AuxiliaryMethods::convertStringToInt(DateWithoutDashes);
}

bool Date::isDateCorrect(string dateString)
{
    string yearString = "";
    string monthString = "";
    string dayString = "";
    int yearInt, monthInt, dayInt;
    size_t textPosition = 0;

    if (dateString.size() != 10)
        return false;

    while (dateString[textPosition] != '-')
    {
        yearString += dateString[textPosition];
        textPosition++;
    }

    yearInt = atoi(yearString.c_str());

    if (yearInt < 2000 || yearInt >= getTodayDate() / 1000)
        return false;

    textPosition = 5;
    while (dateString[textPosition] != '-')
    {
        monthString += dateString[textPosition];
        textPosition++;
    }

    monthInt = atoi(monthString.c_str());

    if (monthInt < 1 || monthInt > 12)
        return false;

    textPosition++;
    while (textPosition < dateString.size())
    {
        dayString += dateString[textPosition];
        textPosition++;
    }

    dayInt = atoi(dayString.c_str());

    if(!isDayCorrect(dayInt, monthInt, yearInt))
        return false;

    else if ((yearInt * 10000 + monthInt * 100 + dayInt) > getTodayDate())
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

    else if ((month == 4) || (month == 6) || (month = 9) || (month == 11))
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
