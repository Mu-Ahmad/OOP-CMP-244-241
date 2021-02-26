#include <iostream>

class Collection {
	int size, currentSize;
	int* data;
public:
	// Constructor
	Collection(int size = 1)
		: size(size), currentSize(0), data(new int[size])
	{}

	// Increment Operator
	Collection& operator+= (const int& ELEMENT) {
		if (ELEMENT < 0)
			data[currentSize++] = ELEMENT;
		else
			data[currentSize++] = -1;

		return *this;
	}

	// Display Function
	void display() const {
		for (int i = 0; i < currentSize; i++)
			std::cout << data[i] << ' ';
		std::cout << '\n';
	}

	// Another constructor
	Collection(int* arr, int size) {
		this->size = size;
		this->currentSize = size;

		for (int i = 0; i < currentSize; i++)
			*this += arr[i];
	}

	// Copy Constructor
	Collection(const Collection& other) {
		this->size = other.size;
		this->currentSize = other.currentSize;
		this->data = new int[size];
		for (int i = 0; i < currentSize; i++)
			this->data[i] = other.data[i];
	}

	// Destructor
	~Collection() {
		delete[] data;
		data = NULL;
		size = currentSize = 0;
	}

	//countElement
	int countElement(const int& key) const {
		int count = 0;
		for (int i = 0; i < currentSize; i++)
			if (key == data[i]) count++;

		if (count == 0) throw "KEY_DOES_NOT_EXIST";

		return count;
	}

	// Assignment
	Collection& operator=(const Collection& other) {
		if (this->currentSize != other.currentSize) throw "INVALID_ASSIGNMENT";

		for (int i = 0; i < currentSize; i++)
			this->data[i] = other.data[i];
	}

	//+operators
	Collection operator+(const Collection& other) {
		if (this->currentSize != other.currentSize) throw "INVALID_ADDITION";

		Collection tempCollection(*this);

		for (int i = 0; i < other.currentSize; i++)
			tempCollection.data[i] += other.data[i];

		return tempCollection;
	}

	//comparison==
	bool operator==(const Collection& other) {
		if (this->currentSize != other.currentSize)
			return false;

		for (int i = 0; i < currentSize; i++)
			if (this->data[i] != other.data[i])
				return false;

		return true;
	}
};


int main() {
	int n; std::cin >> n;
	int operation, input;
	Collection *collection = new Collection(5);
	while (n--) {
		try {
			std::cin >> operation;
			switch (operation) {
			case 1: {
				std::cin >> input;
				collection = new Collection(input);
				break;
			}
			case 2: {
				std::cin >> input;
				(*collection) += input;
				break;
			}
			case 3: {
				collection->display();
				break;
			}
			case 4: {
				// pass an array to create collection object from that array
				// constructor is implemented just fill this driver code
				break;
			}
			case 5: {
				// pass a collection object to create a new one from that object
				// constructor is implemented just fill this driver code
				break;
			}
			case 6: {
				delete collection;
				break;
			}
			case 7: {
				std::cin >> input;
				std::cout << collection->countElement(input) << '\n';
				break;
			}
			case 8: {
				// Assign an existing collection object to another
				// Function is implemented with proper exception handling
				break;
			}
			case 9: {
				// Add two collection objects
				// Function is implemented with proper exception handling
				break;
			}
			case 10: {
				// Compare two collection objects for equality
				// Function is implemented with proper exception handling
				break;
			}
			}
		} catch (const char* error_code) {
			std::cout << error_code << '\n';
		} catch (...) {
			std::cout << "Unhandled Exception\n";
		}
	}
	return 0;
}