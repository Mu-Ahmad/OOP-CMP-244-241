#include <iostream>

using namespace std;

class Employee {
private:
    string firstName, secondName;
    int hours, perHour;

public:
    Employee(string sn, string fn) {//assign 30 to hours and 100 hour rate
        firstName = fn;
        secondName = sn;
        setHours(30);
        setHourRate(100);
    }

    Employee(string sn, string fn, int h, int hR) {//called setters inside
        firstName = fn;
        secondName = sn;
        setHours(h);
        setHourRate(hR);
    }

    void setHours(int h) {
        if (h < 20)
            hours = 20;
        else
            hours = h;
    }

    void setHourRate(int hR) {
        if (hR < 50)
            perHour = 50;
        else
            perHour = hR;
    }

    void increaseHourRate(int inc) {
        perHour += inc;
    }

    void show() {
        cout << firstName << ' ' << secondName << ' '
             << hours << ' ' << perHour << ' '
             << calcSalary() << '\n';
    }

    int calcSalary() {
        int regularSalary = min(40, hours) * perHour;
        if (hours > 40)
            regularSalary += (hours - 40) * 1.5 * perHour;
        return regularSalary;
    }
};

int main() {
    // freopen("input.txt", "r", stdin);
    string sN, fN;
    int h, hR;
    cin >> fN >> sN;
    Employee emp1 (sN, fN);
    cin >> fN >> sN;
    cin.clear();
    cin >> h >> hR;
    Employee emp2 (sN, fN, h, hR);
    emp1.show();
    emp2.show();
    cout << emp1.calcSalary() << ' ' << emp2.calcSalary() << '\n';
    return 0;
}