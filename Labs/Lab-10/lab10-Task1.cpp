//Group 15
// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)

//======================================Task1==============================

#include <iostream>
#include <time.h>

using namespace std;

class Employee {
protected:
	string fName, sName;
	int salary;
public:
	virtual int calcSal() const {return salary;}
	virtual ostream& info(ostream& out) const {
		out << "Fixed Salary = " << salary << '\n';
		return out;
	}
	Employee() {}//temp
	Employee(string fName, string sName, const int& salary)
		: fName(fName), sName(sName), salary(salary) {}
	friend ostream& operator<<(ostream&, const Employee&);
};

ostream& operator<<(ostream& out, const Employee& e) {
	out << "Name: " << e.fName << ' ' << e.sName << '\n';
	e.info(out);
	out << "Salary: " << e.calcSal() << '\n';
	return out;
}

class RegEmp: public Employee {
	int addHours;
public:
	RegEmp(string fName, string sName, const int& salary, const int& addHours = 0)
		: Employee(fName, sName, salary), addHours(addHours) {}
	int getAddHours() const {return addHours;}
	void setAddHours(const int& n) {addHours = n;}
	int calcSal() const {
		return salary + addHours * 100;
	}
	ostream& info(ostream& out) const {
		Employee::info(out);
		out << "Additional Hours = " << addHours << '\n';
	}
};

class ConEmp: public Employee {
	int hRate, hours;
public:
	ConEmp(string fName, string sName, const int& salary, const int& hRate = 10, const int& hours = 0)
		: Employee(fName, sName, salary), hRate(hRate), hours(hours) {}
	void setHours(const int& n) {hours = n;}
	void sethRate(const int& n) {hRate = n;}
	int calcSal() const {
		return salary + hRate * hours;
	}
	ostream& info(ostream& out)const {
		Employee::info(out);
		out << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
};

class DWageEmp: public Employee {
	int hRate, hours;
public:
	DWageEmp(string fName, string sName, const int& hRate = 10, const int& hours = 0)
		: Employee(fName, sName, 0), hRate(hRate), hours(hours) {}
	void setHours(const int& n) {hours = n;}
	void sethRate(const int& n) {hRate = n;}
	int calcSal() const {
		return hRate * hours;
	}
	ostream& info(ostream& out) const {
		Employee::info(out);
		out << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
};


int main() {
	Employee** employees = new Employee*[10];
	srand(time(0));
	int choice;
	for (int i = 0; i < 10; i++) {
		choice = rand() % 3;
		switch (choice) {
		case (0):
			employees[i] = new RegEmp("Regular", "Employee", 1000, i);
			break;
		case (1):
			employees[i] = new ConEmp("Contract", "Employee", 1000, 10, i);
			break;
		case (2):
			employees[i] = new DWageEmp("Daily Wage", "Employee", 100, i + 1);
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << *employees[i] << "\n--------------------------------------\n";

	for (int i = 0; i < 10; i++)
		delete employees[i];
	delete[] employees;
	employees = NULL;
	return 0;
}