//Group 15
// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)

//======================================Task2==============================
#include <iostream>
#include <time.h>
#include <string>

using namespace std;

class Ship {
protected:
	string name, builtIn;
public:
	Ship(string name = "Basic Ship", string builtIn = "Unknown")
		: name(name), builtIn(builtIn) {}
	//accessors
	string getName() const {return name;}
	string getYear() const {return builtIn;}
	//Mutators
	void setName(const string str) { name = str;}
	void setYear(const string str) { builtIn = str;}
	//Virtual Print Function
	void virtual print() const {
		cout << "===========Basic Ship Class========\n"
		     << "Name: " << name << '\n'
		     << "Built In the year " << builtIn << "\n\n";
	}
};

class CruiseShip: public Ship {
	int maxPassengers;
public:
	CruiseShip(string name = "Cruise Ship", string builtIn = "Year Unknown", const int& maxPassengers = 1000)
		: Ship(name, builtIn), maxPassengers(maxPassengers) {}
	//accessor
	int getMaxPassengers() const {return maxPassengers;}
	//mutator
	void setMaxPassengers(const int& n) {maxPassengers = n;}
	//Virtual Print Function
	void virtual print() const {
		cout << "===========Cruise Ship Class========\n"
		     << "Name: " << name << '\n'
		     << "Max No of Passengers: " << maxPassengers << '\n'
		     << "Built In the year " << builtIn << "\n\n";
	}
};

class CargoShip: public Ship {
	int capacity;
public:
	CargoShip(string name = "Cruise Ship", string builtIn = "Year Unknown", const int& capacity = 1000)
		: Ship(name, builtIn), capacity(capacity) {}
//accessor
	int getCargoCapacity() const {return capacity;}
//mutator
	void setCargoCapacity(const int& n) {capacity = n;}
//Virtual Print Function
	void virtual print() const {
		cout << "===========Cargo Ship Class========\n"
		     << "Name: " << name << '\n'
		     << "Cargo Capacity: " << capacity << " Tonnes\n\n";
	}
};

int main() {
	Ship** ships = new Ship*[10];
	srand(time(0));
	int choice;
	for (int i = 0; i < 10; i++) {
		choice = rand() % 3;
		switch (choice) {
		case (0):
			ships[i] = new Ship("Basic Ship", "1990");
			break;
		case (1):
			ships[i] = new CruiseShip("Cruise Ship", "1970", (i + 1) * 10000);
			break;
		case (2):
			ships[i] = new CargoShip("Cargo Ship", "Unknown", (i + 1) * 10000);
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		ships[i]->print();

	for (int i = 0; i < 10; i++)
		delete ships[i];
	delete[] ships;
	ships = NULL;

	return 0;
}