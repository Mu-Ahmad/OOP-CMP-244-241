// Muhammad Ahmad (BCSF19M509)
// Irtaza Faisal (BCSF19M535)
// ==========================Task1============================
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

template<class T>
T sum(T* array, int size) {
	T total(0);
	for (int i = 0; i < size; i++) {
		total = total + array[i];
	}
	return total;
}

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
	friend ostream& operator <<(ostream& out, const Complex& c);
};

ostream& operator <<(ostream& out, const Complex& c) {
	out << setprecision(2) << c.real << " + " << setprecision(2) << c.comp << "i\n";
	return out;
}

int main() {
	srand(time(0));
	int x[] = {3, 2, 4, 6};
	double d[] = {2.3, 4.1, 5.2};
	cout << sum(x, 4) << '\n';
	cout << sum(d, 3) << '\n';
	Complex cArr[3];
	int i;
	cout << "\n=========Complex No============\n";
	for (i = 0; i <  3; i++ )
		cout << cArr[i];
	cout << '\n';
	cout << "Sum: " << sum(cArr, 3) << '\n';
	return 0;
}