#include <ctime>
#include <iostream>
#include <time.h>
using namespace std;

class data {
public:
    int year;
    int day_year;
    int month;
    int day_month;
    int day_week;
};
class data today, count;

int checkMonthMax(int month, int day)
{
    int max;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        max = 31;
    else if (month == 2) { //feb
        if (day == 366) //if leap year
            max = 29;
        else
            max = 28;
    } else
        max = 30;
    return max;
}

int checkLeap(int year)
{
    int day = 365, r1, r2;
    r1 = count.year % 4;
    r2 = count.year % 400;
    if (r1 == 0 || r2 == 0) { // leap year
        day = 366;
    }
    return day;
}

void NuovoCheck(int max, bool check_loop)
{
    count.year = today.year;
    count.month = today.month + 1;
    cout << "mese = " << count.month << endl;
    count.day_month = today.day_month;
    cout << "giorno mese = " << count.day_month << endl;
    count.day_week = today.day_week + 7;
    if (count.day_week > 7)
        count.day_week -= 7;
    cout << "giorno settimana = " << count.day_week << endl;
    count.day_year = today.day_year + 1;
    cout << "giorno anno = " << count.day_year << endl;
    cout << "anno = " << count.year << endl;
    int year_max = today.year + max; // set the max of the year you want to check
    int day_month_max; // set how many days are in a month based of what month it is
    int day_in_year;
    cout << "List of every friday 13th in " << max << " years" << endl;
    for (count.year = count.year; count.year <= year_max; count.year++) { //years
        cout << "\nAnno " << count.year << ":" << endl;
        day_in_year = checkLeap(count.year);
        do { //day in year
            day_month_max = checkMonthMax(count.month, day_in_year); //how many days are in that month
            for (count.day_month = count.day_month; count.day_month <= day_month_max; count.day_month++) { //day in month
                if (count.day_month == 13 && count.day_week == 5) //check friday 13
                    cout << "- " << count.day_month << "/" << count.month << "/" << count.year << endl;
                count.day_week++; //day in week
                if (count.day_week == 8) //reset week
                    count.day_week = 1;
                count.day_year++; //add day in year
            }
            count.day_month = 1; //reset day in month
            count.month++;
            if (count.month == 13)
                count.month = 1; //reset month
        } while (count.day_year <= day_in_year);
        count.day_year = 1; //reset day in year
    }
}

int main()
{
    int max;
    bool check_first_loop;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    today.year = timePtr->tm_year; // years since 1900
    today.year += 1900; // actual year
    today.day_year = timePtr->tm_yday; // day of year
    today.month = timePtr->tm_mon; // month of year
    today.day_month = timePtr->tm_mday; // day of month
    today.day_week = timePtr->tm_wday; // day of week
    cout << "Inserire in quanti anni vuoi vedere venerdi 13" << endl;
    cin >> max;
    NuovoCheck(max, check_first_loop);
}