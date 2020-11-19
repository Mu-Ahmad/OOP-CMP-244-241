#include <iostream>
#include "ShowRoom2.cpp"

using namespace std;

int main(){
	ShowRoom showRoom("ABC Cars", 5);
	showRoom.addCar("Suzuki", 2010, "White", 799, 4, 300000);
	showRoom.addCar("Mercedez", 2018, "White", 1999, 4, 13000000);
	cout << showRoom;
	return 0;
}
