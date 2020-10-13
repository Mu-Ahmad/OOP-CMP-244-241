#include <bits/stdc++.h>

using namespace std;
struct Set {
	int *data, *universalSet, size, uSIZE, currentSize;
	void initUniversal( const int SIZE ){
		uSIZE = SIZE;
		universalSet = new int [uSIZE];
		for ( int i = 0; i < uSIZE; i++ )
			universalSet[i] = i;
	}
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
	void print() const {
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

	Set complement () {
		Set complement;
		complement.init(uSIZE);
		for (int i = 0 ; i < uSIZE ; i++) {
			if(!(isExist(universalSet[i]))) {
				complement.data[complement.currentSize++] = universalSet[i];
			}
		}
		return complement;
	}
	bool isSubset (const Set &set) {
		for ( int i = 0 ; i < set.currentSize ; i++)
			if (!(isExist(set.data[i])))
				return false;
		return true;
	}
	bool isProperSubset (const Set &set) {
		if (isSubset(set) && set.currentSize < currentSize)
			return true;
		return false;
	}
	
	void free(){
			delete data;
	}
};

int main(){
	Set s, s2;
	s.init(10);
	for(int i=0;i<10;i++)
		s.add(i);
	cout << "s:";
	s.print();
	s2.init(20);
	for(int i=0;i<5;i++)
		s2.add(i);
	cout << "s2: ";
	s2.print();

	Set complement;
	complement.init(20);
	s.initUniversal(20);
	complement = s.complement();
	cout << "Complement: ";
	complement.print();

	if(s.isSubset(s2))
		cout << "Set \"s2\" is the subset of set \"s\".\n" ;
	if(!(s2.isSubset(s)))
		cout << "Set \"s\" is not the subset of set \"s2\".\n" ;

		if(s.isProperSubset(s2))
			cout << "Set \"s2\" is the ProperSubsetsubset of set \"s\".\n" ;
		if(!(s.isProperSubset(s)))
			cout << "Set \"s\" is not the ProperSubsetsubset of set \"s\".\n" ;




	cout << "\nDone with it.\n";
	return 0;
}
