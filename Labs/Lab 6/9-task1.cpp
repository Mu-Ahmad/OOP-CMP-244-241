#include <iostream>

class Set {
public:
	int currentSize, size;
	char * data;
	void copy(const Set &s) {
		currentSize =  s.currentSize;
		size = s.size;
		data = new char[size];
		for (int i = 0; i < currentSize; i++)
			data[i] = s.data[i];
	}
	//Constructor
	Set(const int &n = 5): currentSize(0), size(n)
	{
		data = new char[size];
	}

	Set(const Set &s) {
		copy(s);
	}
	//utiltiy functions
	void resize(const int &newSize) {
		data = (char *)realloc(data, newSize * sizeof(char));
		size = newSize;
		currentSize = std::min(currentSize, newSize);
	}
	bool add(const char ELEMENT) {
		if (currentSize == size) {
			// cout << "Failed to add item to set. Capaciy is completely filled.\n";
			return false;
		}
		if (isExist(ELEMENT))
			return false;
		data[currentSize++] = ELEMENT;
		return true;
	}

	bool isExist(const char ELEMENT) const {
		for (int i = 0; i < currentSize; i++)
			if (data[i] ==  ELEMENT)
				return true;
		return false;
	}

	int getIndex(const char ELEMENT) const {
		for (int i = 0; i < currentSize; i++)
			if (data[i] ==  ELEMENT)
				return i;
		return -1;
	}
	//Operator overloading
	Set operator= (const Set& s) {
		this->~Set();
		copy(s);
		return *this;
	}

	Set operator+ (const Set& s) {
		int size = currentSize + s.currentSize;
		Set newSet(size);
		for (int i = 0 ; i < currentSize ; i++)
			newSet.data [newSet.currentSize++] = data [i];
		for (int i = 0 ; i < s.currentSize ; i++)
			newSet.add (s.data[i]);
		return newSet;
	}
	void operator* (const Set& s) {
		std::cout << '{';
		for (int i = 1; i <= currentSize; i++)
			for (int j = 1; j <= s.currentSize; j++) {
				std::cout << '(' << data[i - 1]
				          << ',' << s.data[j - 1] << ')';
				if (i < currentSize or j < s.currentSize)
					std::cout << ',';
			}
		std::cout << "}\n";
	}
	Set operator+ (const char& ELEMENT) {
		add(ELEMENT);
		return *this;
	}
	Set operator- (const Set & s) {
		Set newSet(currentSize);
		for (int i = 0 ; i < currentSize ; i++)
			if (!s.isExist(data[i]))
				newSet.data[newSet.currentSize++] = data[i];
		return newSet;
	}
	Set operator- (const char& ELEMENT) {
		int index = getIndex(ELEMENT);
		if (index != -1) {
			currentSize--;
			for (; index < currentSize ; index++)
				data[index] = data[index + 1];
		}
		return *this;
	}
	bool operator== (const Set & s) {
		for (int i = 0; i < currentSize; i++)
			if (!s.isExist(data[i]))
				return false;
		return true;
	}
	bool operator!= (const Set & s) {
		return !(*this == s);
	}
	//Destructor
	~Set() {
		delete [] data;
		data = nullptr;
	}
};

std::ostream& operator << (std::ostream &out, const Set &s) {
	if (s.currentSize)
		for (int i = 0 ; i < s.currentSize; i++)
			out << s.data[i] << ' ';
	else
		out << "EMPTY SET";
	out << '\n';
	return out;
}

int main() {
	int t; std::cin >> t;
	int choice, op1, op2, op3;
	char ch;
	Set sets[5];
	while (t--) {
		std::cin >> choice;
		switch (choice) {
		case (1):
			std::cin >> op1 >> op2 >> op3;
			sets[op3 - 1] = sets[op1 - 1] + sets[op2 - 1];
			break;
		case (2):
			std::cin >> op1 >> op2;
			sets[op1 - 1] * sets[op2 - 1];
			break;
		case (3):
			std::cin >> op1 >> op2 >> op3;
			sets[op3 - 1] = sets[op1 - 1] - sets[op2 - 1];
			break;
		case (4):
			std::cin >> op1 >> ch;
			sets[op1 - 1] + ch;
			break;
		case (5):
			std::cin >> op1 >> ch;
			sets[op1 - 1] - ch;
			break;
		case (6):
			std::cin >> op1 >> op2;
			if (sets[op1 - 1] == sets[op2 - 1])
				std::cout << "TRUE\n";
			else
				std::cout << "FALSE\n";
			break;
		case (7):
			std::cin >> op1 >> op2;
			if (sets[op1 - 1] != sets[op2 - 1])
				std::cout << "TRUE\n";
			else
				std::cout << "FALSE\n";
			break;
		case (8):
			std::cin >> op1;
			std::cout << sets[op1 - 1];
			break;
		case (9):
			std::cin >> op1 >> op2;
			while (op2--) {
				std::cin >> ch;
				sets[op1 - 1] + ch;
			}
			break;
		case (10):
			std::cin >> op1 >> op2;
			sets[op1 - 1] = sets[op2 - 1];
			break;
		}
	}
	return 0;
}