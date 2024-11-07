#include <iostream>
using namespace std;

class date {
public:
    void getdate(int date_day, int date_month, int date_year);
    void showdate();
    date operator+(const date&date);
    ~date();
private:
    int day, month, year;
};

void date::getdate(int date_day, int date_month, int date_year) {
    if (date_day > 31 or 0 >  date_day or date_month > 12 or 0 > date_month) {
        cout << "incorrect date";
        exit(0);
    }
    day = date_day;
    month = date_month;
    year = date_year;
}

void date::showdate() {
    cout << "date: " << day << "." << month << "." << year << endl;
}

date date::operator+(const date&date) {
    class date result;
    result.year=date.year+year;
    result.month=date.month+month;
    result.day=date.day+day;
    if (result.day > 31) {
        if (result.month%12 == 2) {
            result.month+=1;
            if (result.year % 4 == 0) {
                result.day%=29;
            } else {
                result.day%=28;
            }
        } else if (result.month%12 == 4 or result.month%12 == 6 or result.month%12 == 9 or result.month%12 == 11) {
            result.month+=1;
            result.day%=30;
        } else {
            result.month+=1;
            result.day%=31;
        }
    } else if (result.day == 31) {
        if (result.month % 12 == 2) {
            result.month += 1;
            if (result.year % 4 == 0) {
                result.day %= 29;
            } else {
                result.day %= 28;
            }
        } else if (result.month % 12 == 4 or result.month % 12 == 6 or result.month % 12 == 9 or
                   result.month % 12 == 11) {
            result.month += 1;
            result.day %= 30;
        }
    } else if (result.day == 30) {
        if (result.month % 12 == 2) {
            result.month += 1;
            if (result.year % 4 == 0) {
                result.day %= 29;
            } else {
                result.day %= 28;
            }
        }
    } else if (result.day == 29) {
        if (result.month % 12 == 2) {
            result.month += 1;
            if (result.year % 4 != 0) {
                result.day %= 28;
            }
        }
    }
    if (result.month > 12) {
        result.month%=12;
        result.year += 1;
    }
    return result;
}

date::~date(){}

int main() {
    int d_1, m_1, y_1, d_2, m_2, y_2;
    date Date_1;
    date Date_2;
    cin >> d_1 >> m_1 >> y_1;
    cin >> d_2 >> m_2 >> y_2;
    Date_1.getdate(d_1, m_1, y_1);
    Date_1.showdate();
    Date_2.getdate(d_2, m_2, y_2);
    Date_2.showdate();
    (Date_1+Date_2).showdate();
    return 0;
}