#include <bits/stdc++.h>

using namespace std;
struct Set {
	int *data, size, currentSize;
	void init( const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	}
	bool isExist ( const int ELEMENT ) const {
		int i;
		for ( i = 0; i < currentSize; i++)
			if(ELEMENT == data[i])
				return true;
		return false;
	}
	bool add ( const int ELEMENT ) {
		if ( currentSize == size )
			return false;
		if ( isExist(ELEMENT) )
			return false;
		data[ currentSize++ ] = ELEMENT;
		return true;
	}
	void print() const{
		for( int i = 0; i < currentSize; i++ )
			cout << data[i] << ' ';
		cout << '\n';
	}
	void resize ( const int newSize ){
		data = (int*)realloc(data,newSize*sizeof(int));
		size = newSize;
	}
 	Set Union ( const Set &set ){
		int SIZE = currentSize + set.currentSize;
		Set newSet;
		newSet.init(SIZE);
		int i;
		for ( i = 0 ; i < currentSize ; i++)
			newSet.data [ newSet.currentSize++ ] = data [i];
		for ( i=0 ; i < set.currentSize ; i++)
			newSet.add (set.data[i]);
		return newSet;
	}
	Set intersection ( const Set &s){
		Set newSet;
		int size = currentSize;
		if (currentSize > s.currentSize)	size=s.currentSize;
		newSet.init(size);
		for (int i=0 ; i < currentSize ; i++)
			if ( s.isExist ( data[i] ) )
				newSet.data[ newSet.currentSize++ ] = data[i];
		return newSet;
	}
	Set difference ( const Set &set){
		int SIZE = currentSize;
		int i;
		Set newSet;
		newSet.init(SIZE);
		for (i = 0; i < currentSize; i++ )
			if(!(set.isExist(data[i])))
				newSet.data[newSet.currentSize++] = data[i];
		return newSet;
	}
	void free(){
			delete data;
	}
};

int main(){
	Set s, s2, s3;
	s.init(10);
	for(int i=0;i<10;i++)
		s.add(i);
	cout << "s:";
	s.print();

	 s.resize(20);
	 for(int i=10;i<20;i++)
	 	s.add(-i);
	 cout << "Increased size with new entries:\ns:";
	 s.print();

	 s2.init(20);
	 for(int i=0;i<10;i++)
	 	s2.add(i);
	 s2.add(30);
	 cout << "s2: ";
	 s2.print();
	 cout << "s union s2:";
	 s.Union(s2).print();

	 cout << "s intersection s2:";
	 s.intersection(s2).print();

	s3.init(20);
	for(int i=0;i<5;i++)
		s3.add(i);
	cout << "s3: ";
	s3.print();
	s3 = s.difference(s3);
	cout << "Difference: ";
	s3.print();
	cout << "\nDone with it.\n";
	return 0;
}
