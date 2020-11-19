#include <iostream>
#include "Car.cpp"

using namespace std;

int main(){
	Car c;
	c.set("Suzuki", 2010, "White", 799, 4, 300000);
	cout << c;
	return 0;
}
