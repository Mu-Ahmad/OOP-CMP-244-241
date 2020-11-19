#include <iostream>
#include "ShowRoom3.cpp"

using namespace std;

int main(){
	ShowRoom showRoom("ABC Cars", 5);
	showRoom.addCar("Suzuki Mehran", 2010, "White", 799, 4, 300000);
	showRoom.addCar("Suzuki Surf", 2015, "Black", 2999, 6, 6000000);
	showRoom.addCar("Mercedez", 2018, "White", 1999, 4, 13000000);
	cout << showRoom;
	showRoom.deleteCar(1);
	cout << showRoom;	
	showRoom.addCar("Toyota Corrola", 2018, "Peach", 2018, 4, 3000000);
	cout << showRoom;	
	return 0;
}
