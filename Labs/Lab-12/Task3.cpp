// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)
// ==========================Task3============================
#include <iostream>
#include <iomanip>
#include <ctime>

template<class T>
class Set {
	int currentSize, size;
	bool isExist(const T ELEMENT) const {
		for (int i = 0; i < currentSize; i++)
			if (data[i] == ELEMENT)
				return true;
		return false;
	}
	void resize(const int newSize) {
		data = (T *)realloc(data, newSize * sizeof(T));
		size = newSize;
	}
public:
	T* data;
	Set(const int& n = 5) {
		size = n;
		currentSize = 0;
		data = new T[size];
	}
	Set(T* array, const int& n) {
		size = n;
		currentSize = n;
		data = new T[size];
		for (int i = 0; i < size; i++)
			data[i] = array[i];
	}
	bool add(const T ELEMENT) {
		if (isExist(ELEMENT))
			return false;
		if (currentSize == size)
			resize(size + 1);
		data[currentSize++] = ELEMENT;
		return true;
	}
	Set operator-(const Set &s) const {
		Set newSet(currentSize);
		for (int i = 0 ; i < currentSize ; i++)
			if (!s.isExist(data[i]))
				newSet.data[newSet.currentSize++] = data[i];
		return newSet;
	}

	Set& operator+=(const Set &s) {
		for (int i = 0; i < s.currentSize; i++)
			this->add(s.data[i]);
		return *this;
	}
	int getCurrentSize() const {return currentSize;}
	template <typename U>
	friend std::ostream& operator<<(std::ostream& out, const Set<U>& s);
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Set<T>& s) {
	if (s.currentSize == 0) {
		out << "Empty Set...\n";
		return out;
	}
	for (int i = 0; i < s.currentSize; i++)
		out << s.data[i] << ' ';
	out << '\n';
	return out;
}

template<class T>
class Sets {
	Set<T> sets[4]; //Index 3 == Universal Set;
public:
	void updateUniversalSet(int index) {
		sets[3] += sets[index - 1];
	}
	void load(int index, T* array, const int size) {
		Set<T> temp(array, size);
		sets[index - 1] = temp;
		updateUniversalSet(index);
	}
	void printUniversalSet()const {
		std::cout << "Universal Set: " << sets[3] << '\n';
	}
	void printSets() const {
		std::cout << "=================All Sets===============\n";
		std::cout << "Universal Set: " << sets[3] << '\n';
		std::cout << "Set1: " << sets[0] << '\n';
		std::cout << "Set2: " << sets[1] << '\n';
		std::cout << "Set3: " << sets[2] << '\n';
	}
	void printComplements() const {
		std::cout << "=================Complements===============\n";
		std::cout << "Complement of Set 1: " << sets[3] - sets[0] << '\n';
		std::cout << "Complement of Set 2: " << sets[3] - sets[1] << '\n';
		std::cout << "Complement of Set 3: " << sets[3] - sets[2] << '\n';
	}
};

int main() {
	Sets<int> s;
	int arr1[6] = {1, 2, 3, 4, 5, 6};
	int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int arr3[10] = {6, 7, 8, 9, 10, 11, 12, 13};
	s.load(1, arr1, 6);
	s.load(2, arr2, 10);
	s.load(3, arr3, 8);
	s.printSets();
	s.printComplements();
	arr3[0] = 79;
	s.load(3, arr3, 8);
	s.printSets();
	s.printComplements();
}