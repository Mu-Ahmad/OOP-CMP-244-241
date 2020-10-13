#include <iostream>

using namespace std;

struct Set{
	int *data, currentSize, size;
	void set(const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	}
	bool isExist(const int ELEMENT) const{//Function can't change variables of structure
		for (int i=0;i<currentSize;i++)
			if (data[i] ==  ELEMENT)
				return true;
		return false;
	}
	bool add(const int ELEMENT){
		if (currentSize == size)	return false;
		if (isExist(ELEMENT))		return false;
		data [ currentSize++ ] = ELEMENT;
		return true;
	}
	Set intersection (const Set &s){//s is declared const to made read only
		Set newSet;
		int size = currentSize;
		if (currentSize > s.currentSize)	size=s.currentSize;
		newSet.set(size);
		for (int i=0 ; i < currentSize ; i++)
			if ( s.isExist ( data[i] ) )
				newSet.data[ newSet.currentSize++ ] = data[i];
		return newSet;
	}	
	Set _union (const Set &s){//s is declared const to made read only
		Set newSet;int i;
		int size = currentSize + s.currentSize;
		newSet.set(size);
		//Adding or placing all elements of set 1 into new set
		for ( i=0 ; i < currentSize ; i++)
			newSet.data [ newSet.currentSize++ ] = data [i];
		//Calling add function to add unique values of set 2 in new set
		for ( i=0 ; i < s.currentSize ; i++)
			newSet.add (s.data[i]);
		return newSet;
	}
	void show() const{//Function can't change variables of structure
		if (currentSize == 0 )
			cout << "Empty Set";
		for (int i=0;i<currentSize;i++)
			cout << data[i] << ' ';
		cout << '\n';
	}
	void free(){
		delete []data;
	}
};

int main(){
	struct Set s1, s2;
	s1.set(5);//size is set with value 10
	s1.add(3);
	s1.add(7);
	s1.add(9);
	s1.add(7);
	s1.show();

	srand(time(0));
	int i, value;
	s2.set(5);
	for (i=0;i<5; ){
		value = rand() % 10;
		if (s2.add(value))	i++;
	}
	s2.show();

	Set s3 = s1.intersection(s2);
	s3.show();
	Set s4 = s1._union(s2);
	s4.show();
	s1.free();
	s2.free();
	s3.free();
	s4.free();
	return 0;
}
