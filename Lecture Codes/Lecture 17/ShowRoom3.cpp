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
		noOfCars = 0;
		cars = new Car*[capacity];
		for (int i=0;i<capacity;i++)
			cars[i] = NULL;
	}
	bool addCar(const char *name, int model, const char *color, int cc, int capacity, int price){
		for (int i=0; i < capacity; i++)
			if (cars[i] == NULL){
				cars[i]= new Car;
				cars[i]->set(name, model, color, cc, capacity, price);
				noOfCars++;
				return true;
			}
		return false;
	}
	bool deleteCar(int carNo){
		if (carNo >= capacity || cars[carNo]==NULL)	return false;
		delete cars[carNo];
		cars[carNo] = NULL;
		noOfCars--;
	}
	~ShowRoom(){
		for (int i=0;i<capacity;i++)
			if (cars[i]!=NULL)
				delete cars[i];
		delete []cars;
	}
	friend ostream& operator << (ostream &out, const ShowRoom &s);
};
ostream& operator << (ostream &out, const ShowRoom &s){
	out << '\t' << s.showRoomName<<'\n';
	out << "No of Cars: " << s.noOfCars<<'\n';
	for (int i=0;i<s.capacity;i++)
		if (s.cars[i]!=NULL)//Check object exist or not
			out << *s.cars[i];
	out << '\n';
	return out;
}
