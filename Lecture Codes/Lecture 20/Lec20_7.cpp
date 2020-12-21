#include <iostream>

using namespace std;

class Employee{
	int employeeNo;
protected:
	int salary;
public:
	Employee(int en, int sal):employeeNo(en), salary(sal){	}
	void showSalary(){	cout << "Employee\nSalary:" << salary << '\n'	;	}
};
class RegularEmployee:public Employee{
	int bonus;
public:
	RegularEmployee(int en, int sal, int b):Employee(en, sal), bonus(b){	}
	void showSalary(){	cout << "Regular Employee\nSalary:" << salary+bonus << '\n'	;	}
};
class SalesMan:public Employee{
	int sales;
	int commission;	//percentage of sales
public:
	SalesMan(int en, int sal, int ss, int c):Employee(en, sal), sales(ss), commission(c){	}
	void showSalary(){	cout << "Sales Man\nSalary:" << salary+sales*commission/100 << '\n'	;	}
};
int main(){
	RegularEmployee re(1, 30000, 5000);
	SalesMan sm(2, 10000, 300000, 2);
	re.showSalary();
	sm.showSalary();
	return 0;
}
