//Group: 15
//Irtaza Faisal (535)
//Muhammad Ahmad (509)

#include <iostream>

using namespace std;


//===========================Q1==========================
class PersonData {
	string firstName, lastName, email, city;
	unsigned int houseNo;
	char block;
public:
	//getter
	string getFirstName() const { return firstName;}
	string getLastName() const { return lastName;}
	string getEmail() const { return email;}
	string getCity() const { return city;}
	unsigned int getHouseNo() const {return houseNo;}
	char getBlock() const { return block;}
	//setter
	void setFirstName(string str)  { firstName = str;}
	void setLastName(string str)  { lastName = str;}
	void setEmail(string str)  { email = str;}
	void setCity(string str)  { city = str;}
	void setHouseNo(unsigned int n)  {houseNo = n;}
	void setBlock(char b)  {
		b = toupper(b); //a-z will automatically be converted to A-Z
		block = b;
	}
};
//Writing ostream operator overload by using appropriate getters
ostream& operator<<(ostream& out, const PersonData& data) {
	out << "First Name: " << data.getFirstName() << '\n'
	    << "Last Name: " << data.getLastName() << '\n'
	    << "Email: " << data.getEmail() << '\n'
	    << "House no: " << data.getHouseNo() << '\n'
	    << "Block: " << data.getBlock() << '\n'
	    << "City: " << data.getCity() << '\n';
	return out;
}

class customerData : public PersonData {
	static int count;
	int number;
	bool emailList;
public:
	customerData() {
		setNumber(++count);
		emailList = false; //By default do not add mail to subscribe list
	}
	//getters
	int getNumber() const {return number;}
	bool getmailList() const {return emailList;}
	//setters
	void setNumber(int& n) {number = n;}
	void setEmailList(bool b) {emailList = b;}
};
//Writing ostream operator overload by using appropriate getters
ostream& operator<<(ostream& out, const customerData& data) {
	out << "Customer No: " << data.getNumber() << '\n'
	    << (PersonData)data
	    << "Added to mail list: ";
	if (data.getmailList()) out << "Yes\n";
	else out << "No\n";
	return out;
}
int customerData::count = 0;

//===========================Q2==========================
class Date {
	unsigned int month, day, year;
public:
	//getters
	unsigned int getMonth() const {return month;}
	unsigned int getDay() const {return day;}
	unsigned int getYear() const {return year;}
	//setters
	void setMonth(unsigned int n) {
		if (!n) n++;
		month = (n > 12) ? 12 : n;
	}
	void setDay(unsigned int n) {
		if (!n) n++;
		int maxDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		day = (n > maxDays[month - 1]) ? maxDays[month - 1] : n;
	}
	void setYear(unsigned int n) {year = n;}
};

ostream& operator<<(ostream& out, const Date& data) {
	if (data.getYear() == 0)
		out << "--/--/----";
	else
		out << data.getMonth() << '/' << data.getDay() << '/' << data.getYear();
	out << "\t(Month/Day/Year)";
	return out;
}

class Employee {
	static int count;
	unsigned int number;
	Date hireDate;
public:
	Employee() {
		setNumber(++count);
		hireDate.setYear(0);
	}
	Employee(unsigned int month, unsigned int day, unsigned int year) {
		setNumber(++count);
		setHireDate(month, day, year);
	}
	// getter
	Date getHireDate()const {return hireDate;}
	unsigned int getEmployeeNo()const {return number;}
	// setter
	void setNumber(unsigned int n) {number = n;}
	void setHireDate(unsigned int month, unsigned int day, unsigned int year) {
		hireDate.setMonth(month);
		hireDate.setDay(day);
		hireDate.setYear(year);
	}
};


ostream& operator<<(ostream& out, const Employee& data) {
	out << "Employee No: " << data.getEmployeeNo() << '\n'
	    << "Hiring Date: " << data.getHireDate() << '\n';
	return out;
}
int Employee::count = 0;

class ProductionWorker : public Employee {
	int shift; //1 = day, 2= night
	double perHour;
public:
	ProductionWorker(): Employee(), shift(1), perHour(10.5) {}
	ProductionWorker(int shift, double perHour, unsigned int month, unsigned int day, unsigned int year):
		Employee(month, day, year), perHour(perHour) {
		setShift(shift);
	}
	//getter
	int getShift() const {return shift;}
	double getHourlyRate() const {return perHour;}
	//setter
	void setShift(int n) {shift = (n == 1) ? 1 : 2;}
	void setHourlyRate(double f) {perHour = f;}
};

ostream& operator<<(ostream& out, const ProductionWorker& data) {
	out << Employee(data)
	    << "Shift: " << data.getShift() ;
	if (data.getShift() == 1) out << " (Day)\n";
	else out << " (Night)\n";
	out << "Hourly Rate: " << data.getHourlyRate() << '\n';
	return out;
}

int main() {
//===========================Q1==========================
	cout << "===========================Q1==========================\n";
	customerData customer1, customer2;
	//Using setter functions of base(PersonData) class for customer1
	customer1.setFirstName("Irtaza");
	customer1.setLastName("Faisal");
	customer1.setEmail("bcsf19m535@pucit.edu.pk");
	customer1.setCity("Lahore");
	customer1.setHouseNo(96);
	customer1.setBlock('E');
	//Using setter functions of derived(CustomerData) class for customer1
	customer1.setEmailList(true);
	//Using setter functions of base(PersonData) class for customer2
	customer2.setFirstName("Muhammad");
	customer2.setLastName("Ahmad");
	customer2.setEmail("bcsf19m509@pucit.edu.pk");
	customer2.setCity("Kasur");
	customer2.setHouseNo(32);
	customer2.setBlock('c');
	//Using setter functions of derived(CustomerData) class for customer2
	customer2.setEmailList(false);
	//printing customers
	cout << customer1  << "-------------------------------------\n"
	     << customer2;

//===========================Q2==========================
	cout << "\n===========================Q2==========================\n";
	ProductionWorker worker1;
	ProductionWorker worker2(2, 19.99, 6, 16, 2007);
	cout << worker1  << "-------------------------------------\n"
	     << worker2;
	worker1.setHireDate(18, 25, 2009);
	worker1.setShift(9);
	cout << "-------------------------------------\n";
	cout << worker1;
	cout << "-------------------------------------\n";
	Date date = worker1.getHireDate();
	cout << date << '\n';
	ProductionWorker worker3(2, 00.00, 7, 16, 1957);
	cout << "-------------------------------------\n";
	cout << worker3;
	return 0;
}