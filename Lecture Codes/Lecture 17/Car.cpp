#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Car{
	char name[20];
	int model;//year
	char color[10];
	int cc;//Engine power
	int capacity;//Seating capacity
	int price;
public:
	void set(const char *name, int model, const char *color, int cc, int capacity, int price){
		strcpy(this->name, name);
		this->model = model;
		this->capacity = capacity;
		this->price = price;
		this->cc = cc;
		strcpy(this->color, color);
	}
	friend ostream& operator << (ostream &out, const Car &c);
};
ostream& operator << (ostream &out, const Car &c){
	out << setw(20) << left << c.name << setw(5) << c.model << setw(10) << c.color << setw(5) << right <<
		c.cc << setw(4) << c.capacity << setw(10) << right << c.price << '\n';
	return out;
}
