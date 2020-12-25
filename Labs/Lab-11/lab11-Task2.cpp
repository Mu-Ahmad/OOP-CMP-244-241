//Group 15
// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)

//======================================Task2==============================

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
	virtual void info() const {
		cout << "Fixed Salary = " << salary << '\n';
	}
	Employee() {}//temp
	Employee(string fName, string sName, const int& salary)
		: fName(fName), sName(sName), salary(salary) {}
	virtual void setSalary(const int& newSalary) {salary = newSalary;}
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
	void info() const {
		Employee::info();
		cout << "Additional Hours = " << addHours << '\n';
	}
};

class ConEmp: public Employee {
	int hours, hRate;
public:
	ConEmp(string fName, string sName, const int& salary, const int& hRate = 10, const int& hours = 0)
		: Employee(fName, sName, salary), hours(hours), hRate(hRate) {}
	void setHours(const int& n) {hours = n;}
	void sethRate(const int& n) {hRate = n;}
	int calcSal() const {
		return salary + hRate * hours;
	}
	ostream& info(ostream& out)const {
		Employee::info(out);
		out << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
	void info()const {
		Employee::info();
		cout << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
};

class DWageEmp: public Employee {
	int hours, hRate;
public:
	DWageEmp(string fName, string sName, const int& hRate = 10, const int& hours = 0)
		: Employee(fName, sName, 0), hours(hours), hRate(hRate) {}
	void setHours(const int& n) {hours = n;}
	void sethRate(const int& n) {hRate = n;}
	int calcSal() const {
		return hRate * hours;
	}
	ostream& info(ostream& out) const {
		Employee::info(out);
		out << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
	void info()const {
		Employee::info();
		cout << "Hourly Rate = " << hRate << "\nNo of Hours = " << hours << '\n';
	}
	void setSalary(const int& newSalary) {
		cout << "Salary of Daily Wage Employee Can't be changed its Fixed.\n";
	}
};

class Department {
	string title;
	int maxEmployees, currentEmployees;
	Employee ** employeeList;
public:
	Department(string title, const int& maxEmployees)
		: title(title), maxEmployees(maxEmployees), currentEmployees(0) {
		employeeList = new Employee*[maxEmployees];
		for (int i = 0; i < maxEmployees; i++)
			employeeList[i] = NULL;
	}
	bool addEmployee(const int& choice, const string fName = "", const string sName = "", const int& salary = 0, const int& hours = 0, const int& hRate = 10) {
		switch (choice) {
		case (1):
			employeeList[currentEmployees++] = new RegEmp(fName, sName, salary, hours);
			break;
		case (2):
			employeeList[currentEmployees++] = new ConEmp(fName, sName, salary, hours, hRate);
			break;
		case (3):
			employeeList[currentEmployees++] = new DWageEmp(fName, sName, hours, hRate);
			break;
		}
	}
	bool modifyEmployee(const int& index, const int& newSalary) {
		employeeList[index - 1]->setSalary(newSalary);
		return true;
	}
	bool calcSal(const int& index) {
		cout << "Employee number: " << index << '\n';
		employeeList[index - 1]->info();
		cout << "Salary: " << employeeList[index - 1]->calcSal() << '\n';
		return true;
	}
	bool calcAllSalary() {
		for (int i = 0; i < currentEmployees; i++) {
			calcSal(i + 1);
			cout << "------------------------------------\n";
		}
	}
	bool deleteEmployee(const int& index) {
		delete employeeList[index - 1];
		for (int i = index - 1; i < currentEmployees - 1; i++)
			employeeList[i] = employeeList[i + 1];
		employeeList[--currentEmployees] = NULL;
		return true;
	}
	~Department() {
		for (int i = 0; i < maxEmployees; i++)
			delete employeeList[i];
		delete[] employeeList;
	}
	friend ostream& operator<<(ostream&, const Department&);
};

ostream& operator<<(ostream& out, const Department& d) {
	out << "Department Name: " << d.title << '\n'
	    << "Total no of Employees: " << d.currentEmployees << '\n'
	    << "\t\t<<<< Employee Details >>>>\n";
	if (d.currentEmployees)
		for (int i = 0; i < d.currentEmployees; i++)
			out << *d.employeeList[i] << "--------------------------\n";
	else out << "No Employee in this department...\n";
	return out;
}

class Company {
	string name;
	Department production, finance;
	int noOfEmployees;
public:
	Company(const string name)
		: name(name), production("Production", 20), finance("Finance", 10), noOfEmployees(0) {}
	void addEmployee(const int& departmentNo, const int& employeeType, const string fName = "", const string sName = "", const int& salary = 0, const int& hours = 0, const int& hRate = 10) {
		if (departmentNo == 1)
			production.addEmployee(employeeType, fName, sName, salary, hours, hRate);
		else if (departmentNo == 2)
			finance.addEmployee(employeeType, fName, sName, salary, hours, hRate);
		noOfEmployees++;
	}
	friend ostream& operator<<(ostream&, const Company&);
};

ostream& operator<<(ostream& out, const Company& c) {
	out << "Company Name: " << c.name << '\n'
	    << "No of Employees: " << c.noOfEmployees << '\n'
	    << "Total No of Departments: 2\n"
	    << '\n' << c.production << '\n' << c.finance;
	return out;
}

int main() {
	Company Fictional("Fictional");
	Fictional.addEmployee(1, 2, "Contract", "Employee", 1000, 10, 50);
	Fictional.addEmployee(1, 3, "Daily Wage", "Employee", 100, 60);
	Fictional.addEmployee(2, 1, "Regular", "Employee", 1000, 6);
	Fictional.addEmployee(1, 1, "Favourite", "Regular Employee", 100000, 60);
	cout << Fictional;
}