/*
It fails on test case 2, probably because of operation 8 or 9.
As there is some ambiguity regarding those...
*/


#include <iostream>

class List {
private:
	int current_size, capacity;
	char * data;
	void copyArray(const char* arr, const int& size) {
		for (int i = 0; i < size; i++)
			data[i] = arr[i];
		current_size = size;
	}
public:
	//getters
	int get_capacity() const { return capacity;}
	int get_currentsize() const { return current_size; }
	char * get_data() const { return data;      }

	//Constructor
	List(const int& size = 5) : current_size(0), capacity(size), data(new char[size]) {}
	List(const char* arr, const int& size = 5) : List(size) {copyArray(arr, size);}
	List(const List& l) : List(l.get_capacity()) {copyArray(l.get_data(), l.get_currentsize());}

	//Operator Overloading
	List& operator=(const List& l) {
		resize(l.get_capacity());
		copyArray(l.get_data(), l.get_currentsize());
		return *this;
	}

	List& operator+=(const List& l) {
		if (current_size + l.get_currentsize() > capacity)
			resize(current_size + l.get_currentsize());
		for (int i = 0; i < l.get_currentsize(); i++)
			data[current_size++] = l.get_data()[i];
		return *this;
	}

	//We can rather make a function called delete or remove but ...
	List& operator- (const char& ELEMENT) {
		int index = getIndex(ELEMENT);
		while (index != -1) {
			current_size--;
			for (; index < current_size ; index++)
				data[index] = data[index + 1];
			index = getIndex(ELEMENT);
		}
		return *this;
	}

	List& operator-= (const List& l) {
		for (int i = 0; i < l.get_currentsize(); i++)
			*this - l.get_data()[i];
		return *this;
	}

	List operator+ (const List& l) {
		List newList(capacity + l.get_capacity());
		newList += *this;
		newList += l;
		return newList;
	}

	List operator- (const List& l) {
		List newList(capacity);
		newList += *this;
		newList -= l;
		return newList;
	}

	List& operator+= (const char& ELEMENT) {
		if (capacity == current_size)
			resize(capacity + 1);
		data[current_size++] = ELEMENT;
		return *this;
	}

	//Utility
	void resize(const int &newSize) {
		data = (char *)realloc(data, newSize * sizeof(char));
		capacity = newSize;
		current_size = std::min(current_size, newSize);
	}

	int getIndex(const char ELEMENT) const {
		for (int i = current_size - 1; i > -1; i--)
			if (data[i] ==  ELEMENT)
				return i;
		return -1;
	}

	//Destructor
	~List() {
		delete[] data;
		data = NULL;
	}

};

std::ostream& operator << (std::ostream &out, const List& l) {
	if (l.get_currentsize()) {
		for (int i = 0; i < l.get_currentsize(); i++)
			out << l.get_data()[i] << ' ';
		out << '\n';
	}
	else
		out << "EMPTY LIST\n";
	return out;

}

int main() {
	List* lists[2] = {NULL, NULL};
	int t; std::cin >> t;
	int op1, op2, op3;
	char* arr = new char[5];
	while (t--) {
		std::cin >> op1;
		switch (op1) {
		case (1):
			std::cin >> op1;
			lists[op1 - 1] = new List();
			break;
		case (2):
			std::cin >> op1 >> op2;
			delete[] arr;
			arr = new char[op2];
			for (int i = 0; i < op2; i++)
				std::cin >> arr[i];
			lists[op1 - 1] = new List(arr, op2);
			break;
		case (3):
			std::cin >> op1 >> op2;
			lists[op1 - 1] = new List(*lists[op2 - 1]);
			break;
		case (4):
			std::cin >> op1 >> op2;
			*lists[op1 - 1] = *lists[op2 - 1];
			break;
		case (5):
			std::cin >> op1;
			if (lists[op1 - 1]) {
				delete lists[op1 - 1];
				lists[op1 - 1] = NULL;
			}
			break;
		case (6):
			std::cin >> op1 >> op2;
			*lists[op1 - 1] += *lists[op2 - 1];
			break;
		case (7):
			std::cin >> op1 >> op2;
			*lists[op1 - 1] -= *lists[op2 - 1];
			break;
		case (8):
			std::cin >> op1;
			*lists[op1 - 1] = *lists[0] + *lists[1];
			break;
		case (9):
			std::cin >> op1 >> op2 >> op3;
			*lists[op1 - 1] = *lists[op2 - 1] - *lists[op3 - 1];
			break;
		case (10):
			std::cin >> op1;
			if (lists[op1 - 1])
				std::cout << *lists[op1 - 1];
			else
				std::cout << "NO OBJECT\n";
			break;
		case (11):
			std::cin >> op1 >> arr[0];
			*lists[op1 - 1] += arr[0];
			break;
		}
	}
	return 0;
}