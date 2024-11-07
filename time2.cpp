#include <iostream>

using namespace std;


class Time{


public:
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    Time(int & hours, int & minutes, int & seconds)
    {
        if (hours >= 0 && hours <= 24 && minutes >= 0 && minutes <= 60 && seconds >= 0 && seconds <= 60)
        {
            this->hours = hours;
            this->minutes = minutes;
            this->seconds = seconds;
        }
        else
        {
            cout << "Wrong input, try again";
            exit(1);
        }
    }
    void showtime()
    {
        cout << "Hours: " << hours << "\n";
        cout << "Minutes: " << minutes << "\n";
        cout << "Seconds: " << seconds << "\n";
    }
    Time operator + (const Time& time)
    {
        hours += time.hours;
        minutes += time.minutes;
        seconds += time.seconds;
    }

    ~Time()
    {
    }

};


int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    Time time(a, b, c);
    time.showtime();
    Time time1(a, b, c);
    time + time1;
    time.showtime();
}
