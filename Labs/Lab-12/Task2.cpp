// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)
// ==========================Task2============================
#include <iostream>
#include <iomanip>
#include <ctime>

#define RND1 rand()%10-5
#define RND2 (rand()%10+1)

class Complex {
	double real, comp;
public:
	Complex() {
		real = RND1 + 1.0 / RND2;
		comp = RND1 + 1.0 / RND2;
	}
	Complex(int n) {
		real = n;
		comp = n;
	}
	Complex& operator+(const Complex& n) {
		this->real += n.real;
		this->comp += n.comp;
	}
	bool operator==(const Complex& n) {
		return (real == n.real) and (comp == n.comp);
	}
	friend std::ostream& operator <<(std::ostream& out, const Complex& c);
};

std::ostream& operator <<(std::ostream& out, const Complex& c) {
	out << "(" << std::setprecision(2) << c.real << "+" << std::setprecision(2) << c.comp << "i) ";
	return out;
}

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
	Set(const int& n) {
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
	Set operator-(const Set &s) {
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

int main() {
	srand(time(0));
	Set<int> intSet(5);
	intSet.add(1);
	intSet.add(23);
	intSet.add(39);
	intSet.add(45);
	intSet.add(-76);
	intSet.add(-76);//Already Exist
	intSet.add(-99);
	std::cout << "INTEGER SET: " << intSet;
	Set<Complex> complexSet(5);
	Complex* c;
	for (int i = 0; i < 5; i++) {
		c = new Complex;
		complexSet.add(*c);
		delete c;
	}
	std::cout << "COMPLEX SET" << complexSet << '\n';
	std::cout << "===============================\n";
	Set<int> set1(10);
	Set<int> set2(10);
	for (int i = 0; i < 10; i++) {
		set1.add(rand() % 100);
		set2.add(rand() % 100);
	}
	//Guarented Same Element
	set1.add(99);
	set2.add(99);
	std::cout << "SET1: " << set1 << '\n';
	std::cout << "SET2: " << set2 << '\n';
	std::cout << "SET1 - SET2: " << set1 - set2 << '\n';
	set1 += set2;
	std::cout << "SET1 += SET2: " << set1 << '\n';
	std::cout << "===============================\n";
	Set<Complex> complexSet2(complexSet.data, 5);
	std::cout << "Complex_SET1: " << complexSet << '\n';
	std::cout << "Complex_SET2: " << complexSet2 << '\n';
	std::cout << "Complex_SET1 - Complex_SET2: " << complexSet - complexSet2 << '\n';
	complexSet += complexSet2;
	std::cout << "Complex_SET1 += Complex_SET2: " << complexSet << '\n';
}