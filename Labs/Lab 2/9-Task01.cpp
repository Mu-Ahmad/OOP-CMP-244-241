#include <vector>
#include <iostream>
#include <algorithm>

#define deb2(x, y)          cout<< #x << ' ' << x <<' '<< #y << ' ' << y << endl
using namespace std;

struct Bag {
	int capacity;
	int currentSize;
	int * data;

	void __init__(unsigned int size) {
		data = new int[size];
		capacity = size;
		currentSize = 0;
	}

	void add(int element) {
		data[currentSize++] = element;
	}

	void insert(int element, int index) {
		int i;
		currentSize++;
		for (i = currentSize; i >= index + 1; i--)
			data[i] = data[i - 1];
		data[index] = element;
	}
	void remove(int element) {
		int i;
		for (i = 0; i < currentSize; i++)
			if (data[i] == element)
				break;
		currentSize--;
		for (int j = i; j < currentSize; j++)
			data[j] = data[j + 1];

	}

	void show() {
		for (int i = 0; i < currentSize; i++)
			cout << data[i] << ' ';
		cout << '\n';
	}

	void free() {
		delete data;
	}
};

int main() {
	Bag container;
	int n, temp; cin >> n;
	container.__init__(n);
	cin >> n;
	while (n--) {
		cin >> temp;
		container.add(temp);
	}
	container.show();
	cin >> n;
	container.remove(n);
	container.show();
	cin >> n >> temp;
	container.insert(n, temp);
	container.show();
	container.free();
	return 0;
}
