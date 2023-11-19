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
    cin.sync();

    while(!isDateCorrect(dateString))
    {
        cout << "(Podaj date w formacie rrrr-mm-dd)" << endl;
        dateString = AuxiliaryMethods::loadLine();
    }

    return convertStringDateToInt(dateString);
}

int Date::convertStringDateToInt(string dateString)
{
    string DateWithoutDashes = dateString.erase(4,6) + dateString.substr(5,2) + dateString.substr(8,2);

    return AuxiliaryMethods::convertStringToInt(DateWithoutDashes);
}

int Date::getLastDayOfPreviousMonth()
{
    int today = getTodayDate();
    int previousMonth, year;

    if ((today / 100) % 100 == 1)
    {
        year = (today / 10000) - 1;
        return year * 10000 + 1231;
    }

    else
    {
        previousMonth = (today % 10000) - 1;
        year = today / 10000;
        return year * 10000 + previousMonth * 100 + maxDayNumber(previousMonth, year);
    }

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

    if (dayInt > maxDayNumber(monthInt, yearInt))
        return false;

    else if ((yearInt * 10000 + monthInt * 100 + dayInt) > getTodayDate())
        return false;

    else
        return true;
}

int Date::maxDayNumber(int month, int year)
{
    if (month == 2 && isYearLeap(year) == true)
        return 29;

    else if (month == 2 && isYearLeap(year) == false)
        return 28;

    else if ((month == 4) || (month == 6) || (month = 9) || (month == 11))
        return 30;

    else
        return 31;
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

string Date::addDashesAndChangeDateToString(int dateInt)
{
    string dateWithDashes;
    dateWithDashes = AuxiliaryMethods::convertIntToString(dateInt);
    dateWithDashes.insert(6,"-");
    dateWithDashes.insert(4,"-");

    return dateWithDashes;
}
