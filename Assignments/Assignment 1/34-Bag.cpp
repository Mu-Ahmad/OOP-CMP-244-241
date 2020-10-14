#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Bag {
	int *data, size, current_size, *new_data;
	
	void init (const int SIZE) {
		size = SIZE;
		current_size = 0;
		data = new int [size];
	}
	
	bool isExist (const int ELEMENT) {
		int i;
		for(i = 0 ; i < current_size ; i++) {
			if (data[i] == ELEMENT) {
				return true;
			}
		}
		return false;
	}
	
	void add (const int ELEMENT) {
    	if (current_size == size) {
    		cout << "Size Full!!";
		}
		data[current_size++] = ELEMENT;
	}
	
	void print() {
		int i;
		for (i = 0 ; i < current_size ; i++) {
			cout << data[i] << ' ';
		}
		cout << '\n';
	}
	
	Bag merge (const Bag &bag) {
		int i;
		Bag merging;
		size = current_size + bag.current_size;
		merging.init(size);
		for (i = 0 ; i < current_size ; i++) { 
			merging.data[merging.current_size++] = data[i];
		}
		for (i = 0 ; i < bag.current_size ; i++) {
			merging.add(bag.data[i]);
		}
		return merging;
	}
	
	int indexOf (const int ELEMENT) {
		int i, index;
		if (isExist(ELEMENT)) {
			for (i = 0 ; i < current_size ; i++) {
				if (ELEMENT == data[i])
				index = i;
			}
		}
		else {
			index = -1;
		}
		return index;
	}
	
	void resize (const int newSize) {
		int i;
		if (newSize < current_size) {
			current_size = newSize;
		}
		new_data = new int [newSize];
		for (i = 0 ; i < current_size ; i++) {
			new_data[i] = data[i];
		}
		data = new int [newSize];
		for (i = 0 ; i < current_size ; i++) {
			data[i] = new_data[i];
		}
		size = newSize;
	}
	
	bool has(const Bag &bag) {
		int i, c = 0;
		for (i = 0 ; i < current_size ; i++) {
			if (isExist(bag.data[i])) {
				c++;
			}
		}
		if (c < current_size) {
			return false;
		}
		else {
			return true;
		}
	}
	void free() {
		delete []data;
	}
};

int main() {
	srand(time(0));
	struct Bag bag1, bag2;
	int in, i, size_bag01, size_bag02, new_siz, elem, siz;
	cout << "Enter size of Bag 01 : ";
	cin >> size_bag01;
	bag1.init(size_bag01);
	for (i = 0 ; i < size_bag01 ; i++) {
		bag1.add(rand() % 25);
	}
	cout << "Printing Bag 01 :\n";
	bag1.print();
	cout << '\n';
	
	cout << "Enter size of Bag 02 : ";
	cin >> size_bag02;
	bag2.init(size_bag02); 
	bag2.init(size_bag02);
	for (i = 0 ; i < size_bag02 ; i++) {
		bag2.add(rand() % 25);
	}
	cout << "Printing Bag 02 : \n";
	bag2.print();
	cout << '\n';
	
	Bag bag3 = bag1.merge(bag2);
	cout << "Merging Bag 01 and Bag 02: \n";
	bag3.print();
	cout << '\n';
	
	cout << "Enter element to find in Bag 02 : ";
	cin >> elem;
	in = bag2.indexOf(elem);
	cout << "Index at which "<< elem << " is present : \n" << in;
	
	cout << "\n\nChecking whether Bag 01 has all elements of Bag 02 : ";
	if(bag1.has(bag2)) {
		cout << "\nBag 01 has all elements of Bag 02\n\n";
	}
	else {
		cout << "\nBag 01 does not have all elements of Bag 02\n\n";
	}
	
	cout << "Enter new size of Bag 01 : ";
	cin >> new_siz;
	bag1.resize(new_siz);
	if (new_siz > bag1.current_size) {
		cout << "Entering Additional numbers to fill Bag 01 : \t";
		siz = new_siz - bag1.current_size;
		for (i = 0 ; i < siz ; i++) {
			bag1.add(rand() % 25);
		}
	}
	cout << "After resizing Bag 01 elements are : \n";
	bag1.print();
	
	bag1.free(); bag2.free(); bag3.free();
}
