#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

class Address{
	unsigned int houseNo;
	char block;//Block is single character A-Z
	char area[50];
	char city[20];
public:
	Address(unsigned int houseNo, char block, const char area[], const char city[]){
		this->houseNo = houseNo;
		this->block = block;
		strcpy (this->area, area);
		strcpy (this->city, city);
	}
	void setHouseNo(int houseNo){
		this->houseNo = houseNo;
	}		
	friend ostream& operator << (ostream &, const Address &);
};
ostream& operator << (ostream &output, const Address &a){
	output << a.houseNo << ' ' << a.block << '\n';
	output << a.area << '\n' << a.city <<'\n';
	return output;
}
class Employee{
	int employeeNo;
	char fName[10], sName[10];
	Address address;
	int salary;
public:
	Employee(int en, const char *fn, const char *sn, int s, int hn, char b, const char *ar, const char *city): 
			address(hn, b, ar, city){
		employeeNo = en;
		strcpy(fName, fn);
		strcpy(sName, sn);
		salary = s;
	}
	void setHouseNo(int houseNo){
		address.setHouseNo(houseNo);
	}	
	friend ostream& operator << (ostream &, const Employee &);
};
ostream& operator << (ostream &out, const Employee &e){
	out << "Employee No: " << e.employeeNo << '\n';
	out << "Name: " << e.fName << ' ' << e.sName << '\n';
	out << e.address;
	out << "Salary:" << e.salary << '\n';
	return out;
}
int main(){
	Employee emp1(2,"Qasim","Khan",35000, 7, 'C',"Gulshan-e-Iqbal","Karachi");
	cout << emp1;
	emp1.setHouseNo(3);
	cout << emp1;
	return 0;
}
