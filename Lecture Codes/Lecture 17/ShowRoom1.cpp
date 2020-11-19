#include <iostream>
#include <iomanip>
#include <string.h>
#include "Car.cpp"

using namespace std;

class ShowRoom{
	char showRoomName[100];
	int noOfCars;
	Car *cars;
public:
	ShowRoom(const char *showRoomName, int noOfCars){
		strcpy(this->showRoomName, showRoomName);
		this->noOfCars = noOfCars;
		cars = new Car[noOfCars];
	}
	void set(int carNo, const char *name, int model, const char *color, int cc, int capacity, int price){
		cars[carNo].set(name, model, color, cc, capacity, price);
	}
	~ShowRoom(){
		delete []cars;
	}
	friend ostream& operator << (ostream &out, const ShowRoom &s);
};
ostream& operator << (ostream &out, const ShowRoom &s){
	out << '\t' << s.showRoomName<<'\n';
	for (int i=0;i<s.noOfCars;i++)
		out << s.cars[i];
	out << '\n';
	return out;
}
