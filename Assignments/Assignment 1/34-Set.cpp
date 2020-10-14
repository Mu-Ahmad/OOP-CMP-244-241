#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Set {
	int size, *data, current_size, *universal, *new_data, universal_size;
	void init (const int SIZE) {
		size = SIZE;
		current_size = 0;
		data = new int [size];   
	}
	
	bool isExist (const int ELEMENT) const{
		int i;
		for (i = 0 ; i < current_size ; i++) {
			if (data[i] == ELEMENT) {
				return true;
			}
		}
		return false;
	}
	
	bool add (const int ELEMENT) {
		if (isExist(ELEMENT)) {
			return false;
		}
		if (current_size == size) {
			return false;
		}
		data[current_size++] = ELEMENT;
		return true;
	}
	
	Set _union (const Set &set) {
		int i;
		Set uniion;
		int size = current_size + set.current_size;
		uniion.init(size);
		for (i = 0 ; i < current_size ; i++) {
			uniion.data[uniion.current_size++] = data[i];
		}		
		for (i = 0 ; i < set.current_size ; i++) {
			uniion.add(set.data[i]);
		}
		return uniion;
	}
	
	Set intersection (const Set &set) {
		Set intersection;
		int i, size, big_size;
		if (current_size > set.current_size) {
			size = set.current_size;
			big_size = current_size;
		}
		else {
			size = current_size;                     
			big_size = set.current_size;
		}
		intersection.init(size);
		for (i = 0 ; i < big_size ; i++) {
			if (set.isExist(data[i])) {
				intersection.data[intersection.current_size++] = data[i];
			}
		}
		return intersection;
	}
	
	void print() {
		int i;
		if (current_size == 0) {
			cout << "Empty Set";
		}
		for (i = 0 ; i < current_size ; i++) {
			cout << data[i] << ' ';
		}
		cout << '\n';
	}
	
	Set difference (const Set &set) {
		Set diff;
		int i;
		size = current_size;
		diff.init(size);
		for (i = 0 ; i < current_size ; i++) {
			if (!(set.isExist(data[i]))){
				diff.data[diff.current_size++] = data[i];
			}
		}
		return diff;
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
	
	void init_universal(const int length) {
		int i;
		universal = new int [length];
		universal_size = length;
		for (i = 0 ; i < universal_size ; i++) {
			universal[i] = i;
		}
	}
	
	Set complement () {
		int i;
		Set comp;
		comp.init(universal_size);
		for (i = 0 ; i < universal_size ; i++) {
			if(!(isExist(universal[i]))) {
				comp.data[comp.current_size++] = universal[i];
			}
		}		
		return comp;
	}
	
	bool isSubset (const Set &set) {
		int i, c = 0;
		for (i = 0 ; i < set.current_size ; i++) {
			if (!(isExist(set.data[i]))) {
				return false;
			}
		}
		return true;
	}
	
	bool isProperSubset (const Set &set) {
		if (isSubset(set) && set.current_size < current_size) {
			return true;
		}
		else {
			return false;
		}
	}
	void free() {
		delete []data;
	}
};

int main() {
	srand(time(0));
	struct Set s1, s2, s3, s4, s5, s6;
	int  new_size, i, siz;
	
	s1.init(7);
	s1.add(14); s1.add(7); s1.add(13); s1.add(0); s1.add(10); s1.add(2); s1.add(8);  
	cout << "Printing Set 01\n";
	s1.print();
	cout << '\n';
	
	s2.init(5);
	s2.add(2); s2.add(8); s2.add(13); s2.add(0); s2.add(7);
	cout << "Printing Set 02\n";
	s2.print();
	cout << '\n';
	
	s3 = s1._union(s2);
	cout << "Union of Set 01 and Set 02 is : \n";
	s3.print();
	cout << '\n';
	
	s4 = s1.intersection(s2);
	cout << "Intersection of Set 01 and Set 02 is : \n";
	s4.print();
	cout << '\n';
	
	s5 = s1.difference(s2);
	cout << "The difference of Set 01 and Set 02 is : \n";
	s5.print();	
	cout << '\n';
	
	if(s1.isSubset(s2)) {
		cout << "Set 02 is a subset of Set 01\n\n";
	}
	else {
		cout << "Set 02 is not a subset of Set 01\n\n";
	}
	
	s2.init_universal(15);
	s6 = s2.complement();
	cout << "Complement of Set 02 is : \n";
	s6.print();
	cout << '\n';
	
	if(s1.isProperSubset(s2)) {
		cout << "Set 02 is a proper subset of Set 01\n\n";
	}
	else {
		cout << "Set 02 is not a proper subset of Set 01\n\n";
	}
	
	new_size = 9;
	s1.resize(new_size);
	s1.add(3);
	s1.add(6);
	cout << "After resizing Set 01 new size is : " << new_size << '\n' ;
	s1.print();
	cout << '\n';
	
	s1.free(); s2.free(); s3.free(); s4.free(); s5.free(); s6.free();
}
	
