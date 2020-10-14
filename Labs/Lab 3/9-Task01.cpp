#include <iostream>

using namespace std;

class Address {
private:
	int houseNo;//1-8
	char floor;//a-d
	char block;//A-J
public:
	Address(int h, char f, char b) { //Constructor
		setHouseNo(h);
		setFloor(f);
		setBlock(b);
	}
	//Setters
	void setHouseNo(const int h) {
		if (h < 1 || h > 8)
			houseNo = 1;
		else
			houseNo = h;
	}

	void setFloor(const char f) {
		if (f < 'a' || f > 'd')
			floor = 'a';
		else
			floor = f;
	}

	void setBlock(const char b) {
		if (b < 'A' || b > 'J')
			block = 'A';
		else
			block = b;
	}
	//Getter
	int getHouseNo() const {
		return houseNo;
	}

	char getFloor() const {
		return floor;
	}

	char getBlock() const {
		return block;
	}
	//Other functions used in main
	void show() {
		cout << "House No:" << houseNo << '\n'
		     <<    "Floor:" << floor << '\n'
		     << "Block:" << block << "\n------------\n";
	}

	bool isSameBlock(const Address &in) const {
		if (block == in.getBlock())
			return true;
		return false;
	}

	bool hasUpperFloor(const Address &in) const {
		if (floor > in.getFloor())
			return true;
		return false;
	}

};

int main() {
	// freopen("input.txt", "r", stdin);
	int h;
	char f, b;
	cin >> h >> f >> b;
	Address a1(h, f, b);
	cin >> h >> f >> b;
	Address a2(h, f, b);
	a1.show();
	a2.show();
	if (a1.isSameBlock(a2))
		cout << "has same block\n";
	else
		cout << "has different block\n";
	cin >> f;
	a1.setFloor(f);
	// a1.show();
	// a2.show();
	if (a1.hasUpperFloor(a2))
		cout << "has upper floor\n";
	else
		cout << "has same or lower floor\n";
	a2.setFloor('c');
	cout << "A2 has floor:" << a2.getFloor() << '\n';
	cout << "Block:" << a2.getBlock() << '\n';
	cout << "House no:" << a1.getHouseNo() << '\n';
	return 0;
}