#include <iostream>
#include "ShowRoom1.cpp"

using namespace std;

int main(){
	ShowRoom showRoom("ABC Cars Plannet", 2);
	showRoom.set(0, "Suzuki", 2010, "White", 799, 4, 300000);
	showRoom.set(1, "Mercedez", 2018, "White", 1999, 4, 13000000);
	cout << showRoom;
	return 0;
}
