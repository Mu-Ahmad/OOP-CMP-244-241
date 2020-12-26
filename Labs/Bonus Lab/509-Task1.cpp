#include <iostream>

class Room {
	float length, width, height;
public:
	Room(float length = 14, float width = 14, float height = 11) {
		setDimensions(length, width, height);
	}
	float getArea() const {
		return length * width;
	}

	float getVolume() const {
		return length * width * height;
	}

	void setDimensions(float length, float width, float height) {
		this->length = length;
		this->width = width;
		this->height = height;
	}

	friend std::ostream& operator<<(std::ostream& out, const Room& other) {
		out << "Length: " << other.length << '\n'
		    << "Width: " << other.width << '\n'
		    << "Height: " << other.height << '\n'
		    << "Area: " << other.getArea() << '\n'
		    << "Volume: " << other.getVolume() << '\n';
		return out;
	}
};

class House {
	int noOfRooms;
	Room* rooms;
public:
	House(int noOfRooms = 2)
		: noOfRooms(noOfRooms) {
		rooms = new Room[noOfRooms];
	}

	int getnoOfRooms() const {return noOfRooms;}

	void printRoominfo(int index) const {
		std::cout << "Room No " << index << ":\n------------\n"
		          << rooms[index - 1] << '\n';
	}

	void printAllRooms() const {
		std::cout << "Total Number of Rooms: " << noOfRooms << "\n";
		for (int i = 0; i < noOfRooms; i++)
			printRoominfo(i + 1);
	}

	void printAreaVolume() const {
		float totalVolume, totalArea;
		for (int i = 0; i < noOfRooms; i++) {
			totalArea += rooms[i].getArea();
			totalVolume += rooms[i].getVolume();
		}
		std::cout << "Total Area of House: " << totalArea << '\n'
		          << "Total Volume of House: " << totalVolume << '\n';
	}

	void setDimensions(int index, float length, float width, float height) {
		rooms[index - 1].setDimensions(length, width, height);
	}

	~House() {
		delete[] rooms;
	}
};

int main() {
	House myHouse(5);
	myHouse.printRoominfo(3);
	myHouse.printAreaVolume();
	std::cout << "---------------------------------\nAfter Changing dimensions of a room:\n-----------------------------------\n";
	myHouse.setDimensions(3, 5.7, 8, 10);
	myHouse.printRoominfo(3);
	myHouse.printAreaVolume();
	std::cout << "-----------------------------\nPrinting All Rooms:\n-----------------------------\n";
	myHouse.printAllRooms();
	return 0;
}