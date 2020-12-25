#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;
void solve();
//Cabin
class Cabin {
	int id, assigned_to;
	static int count;
public:
	//Constructor
	Cabin(const int& id): id(++count), assigned_to(0) {}
	Cabin(): id(-1), assigned_to(0) {}

	void assign_to(const int& employee_id) {
		assigned_to = employee_id;
	}

	int get_assign_to() {
		return assigned_to;
	}

	void set_id(const int& n) {id = n;}
	int get_id() const {return id;}

	static int set_count(const int& n) {count = n;}
	static int get_count() {return count;}

	friend ostream& operator << (ostream &out, const Cabin &c);
};

ostream& operator << (ostream &out, const Cabin &c) {
	out << "Cabin Id: " << c.id << '\n'
	    << "Assigned to: ";
	if (c.assigned_to == 0)
		out << "None\n";
	else
		out << c.assigned_to << "(Employee ID)\n";
	out << "------------------------------------\n\n";
	return out;
}

int Cabin::count = 0;
//Employee
class Employee {
	int id, assigned_to;
	static int count;
	char name[20], designation[50];
public:
	Employee(const int& id): id(++count) , assigned_to(0) {set("", "");}
	Employee(): id(-1) , assigned_to(0) {set("", "");}

	void set(const char* name, const char* designation) {
		strcpy(this->name, name);
		strcpy(this->designation, designation);
	}

	void assign_to(const int& cabin_id) {
		assigned_to = cabin_id;
	}

	int get_assign_to() {
		return assigned_to;
	}

	void set_id(const int& n) {id = n;}
	int get_id() const {return id;}

	static int set_count(const int& n) {
		count = n;
	}

	static int get_count() {return count;}

	friend ostream& operator << (ostream &out, const Employee &e);
};

ostream& operator << (ostream &out, const Employee &e) {
	out << "Employee ID:\t" << e.id << '\n'
	    << "Name:\t\t" << e.name << '\n'
	    << "Designation:\t" << e.designation << '\n';
	if (e.assigned_to == 0)
		out << "Has a cabon:\tNO\n";
	else
		out << "Has a cabon(ID):\t" << e.assigned_to << '\n';
	out << "------------------------------------\n\n";
	return out;
}

int Employee::count = 0;

//Cabin List
class Cabin_List {
	int currentSize, capacity;
	Cabin* record;
public:
	Cabin_List(Cabin* record, const int size):
		currentSize(size), capacity(size + 20) {
		this->record = record;
	}

	int get_currentSize()const {return currentSize;}

	bool remove_cabin(const int& id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == id) {
				record[i].set_id(-1);
				currentSize--;
				return true;
			}
		return false;
	}

	bool add_cabin() {
		if (currentSize == capacity)
			return false;
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == -1) {
				record[i] = Cabin(7);
				currentSize++;
				return true;
			}
		return false;
	}

	bool assign_to(const int& cabin_id, const int& employee_id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == cabin_id ) {
				if (record[i].get_assign_to() != 0)
					return false;
				record[i].assign_to(employee_id);
				return true;
			}
	}

	int unassign(const int& id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == id) {
				int temp = record[i].get_assign_to();
				record[i].assign_to(0);
				return temp;
			}
		return 0;
	}
	~Cabin_List() {delete[] record;}

	friend ostream& operator << (ostream & out, const Cabin_List & c_l);
};

ostream& operator << (ostream &out, const Cabin_List &c_l) {
	if (c_l.currentSize == 0) {
		out << "Its Empty(No Cabins)...\n";
		return out;
	}
	for (int i = 0; i < c_l.capacity; i++)
		if (c_l.record[i].get_id() != -1)
			out << c_l.record[i];
	return out;
}

//Employee List
class Employee_List {
	int currentSize, capacity;
	Employee* record;
public:
	Employee_List(Employee* record, const int size):
		currentSize(size), capacity(size + 20) {
		this->record = record;
	}

	int get_currentSize()const {return currentSize;}

	bool remove_employee(const int& id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == id) {
				record[i].set_id(-1);
				currentSize--;
				return true;
			}
		return false;
	}

	bool add_employee(const char* name, const char* designation) {
		if (currentSize == capacity)
			return false;
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == -1) {
				record[i] = Employee(7);
				record[i].set(name, designation);
				currentSize++;
				return true;
			}
		return false;
	}

	bool assign_to(const int& employee_id, const int& cabin_id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == employee_id ) {
				if (record[i].get_assign_to() != 0)
					return false;
				record[i].assign_to(cabin_id);
				return true;
			}
	}

	int unassign(const int& id) {
		for (int i = 0; i < capacity; i++)
			if (record[i].get_id() == id) {
				cout << "It was previously assigned to Employee: " << id << '\n';
				int temp = record[i].get_assign_to();
				record[i].assign_to(0);
				return temp;
			}
		return 0;
	}

	~Employee_List() {delete[] record;}

	friend ostream& operator << (ostream & out, const Employee_List & e_l);
};

ostream& operator << (ostream &out, const Employee_List &e_l) {
	if (e_l.currentSize == 0) {
		out << "Its Empty(No Employees)...\n";
		return out;
	}
	for (int i = 0; i < e_l.capacity; i++)
		if (e_l.record[i].get_id() != -1)
			out << e_l.record[i];
	return out;
}


int main() {
	fstream file, file1;
	int count1(0), count2(0);
	file.open("Employee.bin", ios::binary | ios::in);
	if (file.fail()) {
		ofstream out("Employee.bin");
		out.close();
		file.open("Employee.bin", ios::binary | ios::in);
	}
	file1.open("Cabin.bin", ios::binary | ios::in);
	if (file1.fail()) {
		ofstream out("Cabin.bin");
		out.close();
		file1.open("Cabin.bin", ios::binary | ios::in);
	}
	file.seekg(0, ios::end);
	file1.seekg(0, ios::end);
	count1 = file.tellg() / sizeof(Employee);
	count2 = file1.tellg() / sizeof(Cabin);
	file.seekg(0);
	file1.seekg(0);
	Employee::set_count(count1);
	Cabin::set_count(count2);
	Cabin* _c_l = new Cabin[count1 + 20];
	Employee* _e_l = new Employee[count2 + 20];
	file.read((char *)_e_l, sizeof(Employee) * count1);
	file1.read((char *)_c_l, sizeof(Cabin) * count2);
	file.close();
	file1.close();
	Cabin_List c_l(_c_l, count1);
	Employee_List e_l(_e_l, count2);
	int choice, choice1;
	char quit;
	char name[20], designation[50];
	do {
		cout << "\n=================================================\n"
		     << "Press q to quit\n"
		     << "Press 1 to see all cabins\n"
		     << "Press 2 to see all Employees\n"
		     << "Press 3 to add a cabin\n"
		     << "Press 4 to add an Employee\n"
		     << "Press 5 to remove a cabin\n"
		     << "Press 6 to remove an Employee\n"
		     << "Press 7 to assign a Cabin to Employee\n"
		     << "Press 8 to cancel an assigned Cabin to Employee\n"
		     << "=================================================\n";
		cin >> quit;
		switch (quit) {
		case ('1'):
			cout << c_l;
			break;
		case ('2'):
			cout << e_l;
			break;
		case ('3'):
			c_l.add_cabin();
			cout << "Cabin Added Succesfully\n";
			break;
		case ('4'):
			cout << "Write name: ";
			cin.ignore();
			cin.getline(name, 20);
			cout << "Write designation: ";
			cin.getline(designation, 50);
			e_l.add_employee(name, designation);
			cout << "Employee Added Succesfully\n";
			break;
		case ('5'):
			cout << "Enter the Cabin ID: ";
			cin >> choice;
			c_l.remove_cabin(choice);
			break;
		case ('6'):
			cout << "Enter the Employee ID: ";
			cin >> choice;
			e_l.remove_employee(choice);
			break;
		case ('7'):
			cout << "Enter the Cabin ID: ";
			cin >> choice;
			cout << "Enter the Employee ID: ";
			cin >> choice1;
			if (!c_l.assign_to(choice, choice1))
				cout << "Cabin is Already Assigned to another emplyee.\n";
			else if (!e_l.assign_to(choice1, choice)) {
				cout << "Employee already has a cabin first unassign it!\n";
				c_l.unassign(choice);
			}
			else
				cout << "Cabin is Assigned Succesfully.\n";
			break;
		case ('8'):
			cout << "Enter the Cabin No: ";
			cin >> choice;
			int id = c_l.unassign(choice);
			if (id)
				e_l.unassign(id);
			else
				cout << "The Cabin was not Assigned to anyone.\n";
			break;
		}
	} while (quit != 'q');
	file.open("Employee.bin", ios::binary | ios::out);
	file.write((char *)_e_l, sizeof(Employee) * e_l.get_currentSize());
	file.close();
	file1.open("Cabin.bin", ios::binary | ios::out);
	file1.write((char *)_c_l, sizeof(Cabin) * c_l.get_currentSize());
	file1.close();
	return 0;
}

