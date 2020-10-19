#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Time {
    private:
        int hours;
        int minutes;
        int seconds;
        char AM_PM;
    public:
        void set (char AM_PM, int hours, int minutes, int seconds) {
            this->AM_PM = AM_PM;
            if (hours < 0 || hours > 12) {
                this->hours = 1;
            }
            else {
                this->hours = hours;
            }
            if (minutes < 0 || minutes > 59) {
                this->minutes = 0;
            }
            else {
                this->minutes = minutes;
            }
            if (seconds < 0 || seconds > 59) {
                this->seconds = 0;
            }
            else { 
                this->seconds = seconds;
            }
        }
        void set (char AM_PM, int hours, int minutes) {
            this->AM_PM = AM_PM;
            if (hours < 0 || hours > 12) {
                this->hours = 1;
            }
            else {
                this->hours = hours;
            }
            if (minutes < 0 || minutes > 59) {
                this->minutes = 0;
            }
            else {
                this->minutes = minutes;
            }
            seconds = 0;
        }
        void set (char AM_PM, int hours) {
            this->AM_PM = AM_PM;
            if (hours < 0 || hours > 12) {
                this->hours = 1;
            }
            else {
                this->hours = hours;
            }
            minutes = 0;
            seconds = 0;
        }
        void set (char AM_PM) {
            this->AM_PM = AM_PM;
            hours = 1;
            minutes = 0;
            seconds = 0;
        }
        void addSec (int moreSeconds) {
            seconds += moreSeconds;
            if (seconds > 59) {
               addMin (seconds / 60);
               seconds -= 60;
            }
        }
        void addMin (int moreMinutes) {
            minutes += moreMinutes;
            if (minutes > 59) {
                addHour (minutes / 60);
                minutes -= 60;
            }
        }
        void addHour (int moreHours) {
            hours += moreHours;
            if (hours > 12) {
                hours -= 12;
                if (AM_PM == 'A') {
                    AM_PM = 'P';
                }
                else {
                    AM_PM = 'A';
                }
            }
        }
        void show () {
            cout << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << ' ';
            if (AM_PM == 'A') {
                cout << "AM" << '\n';
            }
            else {
                cout << "PM" << '\n';
            }
        }
};

int main() {
    int noOfValues, min, sec, hour, i, incOps, x = 1, objNo, incNo, value;
    char am_pm;
    Time t[4];
    for (i = 0 ; i < 4 ; i++) {
        cin >> noOfValues;
        if (noOfValues == 4) {
            cin >> am_pm >> hour >> min >> sec;
            t[i].set(am_pm, hour, min, sec);
        }
        else if(noOfValues == 3) {
            cin >> am_pm >> hour >> min;
            t[i].set(am_pm, hour, min);
        }
        else if(noOfValues == 2) {
            cin >> am_pm >> hour;
            t[i].set(am_pm, hour);
        }
        else if(noOfValues == 1) {
            cin >> am_pm;
            t[i].set(am_pm);
        }
    }
    for (i = 0 ; i < 4 ; i++) {
        t[i].show();
    }
    cin >> incOps;
    while (x <= incOps) {
        cin >> objNo >> incNo >> value;
        if (incNo == 1) {
            t[objNo - 1].addHour(value);
            t[objNo - 1].show();
            x++;
        }
        else if (incNo == 2) {
            t[objNo - 1].addMin(value);
            t[objNo - 1].show();
            x++;
        }
        else if (incNo == 3) {
            t[objNo - 1].addSec(value);
            t[objNo - 1].show();
            x++;
        }
    }
    return 0;
}

