#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Employee{
    
private: 
    string firstName;
    string secondName;
    int hours;
    int hourRate;
    
public:

Employee(string fn, string sn) { //assign 30 to hours and 100 hour rate
    hours = 30;
    hourRate = 100;
    secondName = fn;
    firstName = sn;
}    

Employee(string fn, string sn, int h, int hR) {//called setters inside
     secondName = fn;
    firstName = sn;
    setHours(h);
    setHourRate(hR);
}
void setHours(int h) {
    if (h < 20) {
        hours = 20;
    }
    else {
        hours = h;
    }
}

void setHourRate(int hR) {
    if (hR < 50) {
        hourRate = 50;
    }
    else {
        hourRate = hR;
    }
}

void increaseHourRate(int inc) {
    hourRate += inc;
}

void show() {
    cout << firstName << ' ' << secondName << ' ' << hours << ' ' << hourRate << ' ' <<  calcSalary() << '\n';
}

int calcSalary() {
    int sal = 0, newsal = 0, newhour = 0;
      if (hours > 40) {
        sal = 40 * hourRate;
        newhour = hours - 40;
        newsal = (newhour * hourRate) + ((newhour * hourRate) / 2);
        sal = sal + newsal;
    }
    else {
        sal = hours * hourRate;
    }
    return sal;
}
};

int main(){

string sN, fN;

int h, hR;

cin>>fN>>sN;

Employee emp1 (sN, fN);

cin>>fN>>sN;

cin.clear();

cin>>h>>hR;

Employee emp2 (sN, fN, h, hR);

emp1.show();

emp2.show();

cout << emp1.calcSalary() << ' ' << emp2.calcSalary() << '\n';

return 0;
}

