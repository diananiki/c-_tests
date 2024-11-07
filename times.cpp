#include <iostream>
using namespace std;

class time {
public:
    void gettime(int time_hours, int time_minutes, int time_seconds);
    void showtime();
    time operator+(const time&time);
    ~time();
private:
    int hours, minutes, seconds;
};

void time::gettime(int time_hours, int time_minutes, int time_seconds) {
    if (time_hours > 24 or 0 > time_hours or time_minutes > 60 or 0 > time_minutes or time_seconds > 60 or 0 > time_seconds) {
        cout << "incorrect time";
        exit(0);
    }
    hours = time_hours;
    minutes = time_minutes;
    seconds = time_seconds;
}

void time::showtime() {
    cout << "time: " << hours << ":" << minutes << ":" << seconds << endl;
}

class time time::operator+(const time&time) {
    ///заебешься///
    class time result;
    result.hours=time.hours+hours;
    result.minutes=time.minutes+minutes;
    result.seconds=time.seconds+seconds;
    if (result.seconds > 60) {
        result.minutes+=1;
        result.seconds%=60;
    }
    if (result.minutes > 60) {
        result.hours+=1;
        result.minutes%=60;
    }
    result.hours%=24;
    return result;
}

time::~time(){}

int main() {
    int h_1, m_1, s_1, h_2, m_2, s_2;
    class time Time_1;
    class time Time_2;
    cin >> h_1 >> m_1 >> s_1;
    cin >> h_2 >> m_2 >> s_2;
    Time_1.gettime(h_1, m_1, s_1);
    Time_1.showtime();
    Time_2.gettime(h_2, m_2, s_2);
    Time_2.showtime();
    (Time_1+Time_2).showtime();
    return 0;
}