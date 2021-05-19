#include <ctime>
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
//Programs by Francesco Pagliaccia 
string Week[7]={"Monday","Tuesday","Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

struct data {
    int year;
    int day_year;
    int month;
    int day_month;
};
struct data today, count, set, start;

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

int checkMonthMax(int month, int year)
{
    int max, day = checkLeap(year);
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)  // jan, mar, may, jul, aug, oct, dec
        max = 31;
    else if (month == 2) { // feb
        if (day == 366)    // if leap year
            max = 29;
        else
            max = 28;
    } else  // apr, jun, sep, nov
        max = 30;
    return max;
}

bool CheckData(string date, int s){
    bool check = false;
    string y, d, m; 
    int day, month, year;
    char chck1 = date[2], chck2 = date[5];
    if(chck1 == '/' && chck2 == '/'){  // check if string date has / in between the numbers
        y = date.substr(6, 4);
        year = stoi(y);
        m = date.substr(3, 2);
        month = stoi(m);
        if(month > 0 && month <= 12){  // check month is correct
            d = date.substr(0, 2);
            day = stoi(d);
            if(day > 0 && day <= checkMonthMax(month, year))  // check day is correct
                check = true;
        }
        if(s == 2 && year < count.year){  // if arrival date is smaller than starting date
            check = false;
        }
    }
    if(s == 1){  // starting date
        start.year = year;
        start.day_month = day;
        start.month = month; 
    }else{       // arrival date
        set.year = year;
        set.day_month = day;
        set.month = month; 
    }
    return check;
}

int countDayYear(int d, int m, int y){
    int day = d;
    for(int i=1;i<m;i++){
        day += checkMonthMax(i, y);  // for every month add day of the month
    }
    return day-1;
}

void printLeft(int day, int month, int year){
    int cntDay = day, cntMonth = 0, cntYear = 0;
    int n = cntDay/30;    // average days in a month
    cntMonth += n;
    cntDay -= n*30;
    n = cntMonth/12;      // month in a year
    cntYear += n;
    cntMonth -= n*12;
    cout<<"\n\nMancano "<<cntDay<<" giorni, "<<cntMonth<<" mesi e "<<cntYear<<" anni"<<endl;
    cout<<"\n\nOppure mancano circa "<<day<<" giorni o "<<month<<" mesi o "<<year<<" anni"<<endl;
}

void CheckGiorni(int s){
    bool check = false;
    cout<<"\nAnno di partenza: "<<count.day_month<<"/"<<count.month<<"/"<<count.year<<endl;
    cout<<"Anno d'Arrivo: "<<set.day_month<<"/"<<set.month<<"/"<<set.year<<endl;
    int cntYear=0, cntMonth=0, cntDay=0;
    for (count.year = count.year; count.year <= set.year; count.year++) { // years
        int day_in_year = checkLeap(count.year);
        do {  // day in year
            int day_month_max = checkMonthMax(count.month, count.year); // how many days are in that month
            for (count.day_month = count.day_month; count.day_month <= day_month_max; count.day_month++) {  // day in month
                if(count.month == set.month && count.day_month == set.day_month && count.year == set.year)  // check if count date is the same as set date
                    break;
                cntDay++;          // add a day to the final counter
                count.day_year++;  // add a day in year
            }
            if(count.month == set.month && count.day_month == set.day_month && count.year == set.year)  // check if count date is the same as set date
                break;
            count.day_month = 1;  // reset day in month
            count.month++;
            cntMonth++;           // add a month to the final counter
            if (count.month == 13)
                count.month = 1;  // reset month
        } while (count.day_year <= day_in_year);
        if(count.month == set.month && count.day_month == set.day_month && count.year == set.year)  // check if count date is the same as set date
            break;
        count.day_year = 1;  // reset day in year
        cntYear++;           // add a year to final counter
    }
    printLeft(cntDay, cntMonth, cntYear);
}

int main()
{
    int max, scelta;
    string dateStart, dateTo;
    bool check;
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    today.year = timePtr->tm_year;      // years since 1900
    today.year += 1900;                 // actual year
    today.day_year = timePtr->tm_yday;  // day of year
    today.month = timePtr->tm_mon + 1;      // month of year
    today.day_month = timePtr->tm_mday; // day of month
    cout<<"OGGI:"<<endl;
    cout<<"Anno: "<<today.year<<", Mese: "<<today.month<<", Giorno: "<<today.day_month<<endl;
    cout<<"Giorno dell'anno: "<<today.day_year<<endl;
    do{
        do{
            cout<<"\nInserire la data di partenza: manuale(1) o oggi(2)"<<endl;
            cin>>scelta;
        }while(scelta!=1 && scelta!=2);
        if(scelta == 1){
            do{
                cout<<"\nInserire la data di partenza (DD/MM/YYYY)"<<endl;
                cin>>dateStart;
                check = CheckData(dateStart, 1);
                if(!check)
                    cout<<"\nInserire data corretta"<<endl;
            }while(!check);
            count.month = start.month;
            count.day_month = start.day_month;
            count.year = start.year;
            count.day_year = countDayYear(start.day_month, start.month, start.year);
            check = false;
        }else{
            count.month = today.month;
            count.day_month = today.day_month;
            count.year = today.year;
            count.day_year = today.day_year;
        }
        do{
            cout << "Inserire data d'arrivo (DD/MM/YYYY)" << endl;
            cin>>dateTo;
            check = CheckData(dateTo, 2);
            if(set.year < start.year)
                check = false;
            if(!check)
                cout<<"\nInserire data corretta"<<endl;
        }while(!check);
        CheckGiorni(scelta);
        cout<<"\nInserire 0 per uscire o altro per continuare"<<endl;
        cin>>scelta;
    }while(scelta!=0);
}