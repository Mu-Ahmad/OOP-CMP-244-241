#include <iostream>
#include <iomanip>
#include <string.h>
#include "Car.cpp"

using namespace std;

class ShowRoom{
	char showRoomName[100];
	int capacity;//total possible cars
	int noOfCars;//No of cars in showroom currently
	Car **cars;
public:
	ShowRoom(const char *showRoomName, int capacity){
		strcpy(this->showRoomName, showRoomName);
		this->capacity = capacity;
		this->noOfCars = 0;
		cars = new Car*[capacity];
		for (int i=0;i<capacity;i++)
			cars[i] = NULL;
	}
	bool addCar(const char *name, int model, const char *color, int cc, int capacity, int price){
		if (noOfCars < capacity){
			cars[noOfCars]= new Car;
			cars[noOfCars]->set(name, model, color, cc, capacity, price);
			noOfCars++;
			return true;
		}
		return false;
	}
	~ShowRoom(){
		for (int i=0;i<noOfCars;i++)
			delete cars[i];
		delete []cars;
	}
	friend ostream& operator << (ostream &out, const ShowRoom &s);
};
ostream& operator << (ostream &out, const ShowRoom &s){
	out << '\t' << s.showRoomName<<'\n';
	for (int i=0;i<s.noOfCars;i++)
		out << *s.cars[i];//Indirection operator required because cars[i] is a pointer
	out << '\n';
	return out;
}
