#include <iostream>
#include <algorithm>  
#include <vector> 
using namespace std;

struct Set{
	int *data, currentSize, size;
	//int UniversalSet[10] = {1,2,3,4,5,6,7,8,9};
	void init (const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	   /* for (i=0;i<size; ){
		value = rand() % 100;
		if (s2.add(value))	i++;
	}
*/	
	    
	}
	void resize (const int newSize){
           
           int newarray[currentSize];
           for(int i=0;i<currentSize;i++)
           newarray[i] = data[i];
           delete []data;
           size = newSize;
    		data = new int[newSize];
    		for(int i=0;i<currentSize;i++)
           data[i] = newarray[i];
	}
	bool isExist(const int ELEMENT) const{
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
	Set intersection (const Set &set){
		Set newSet;
		int size = currentSize;
		if (currentSize > set.currentSize)	size=set.currentSize;
		newSet.init(size);
		for (int i=0 ; i < currentSize ; i++)
			if ( set.isExist ( data[i] ) )
				newSet.data[ newSet.currentSize++ ] = data[i];
		return newSet;
	}	
	Set _union (const Set &set){
		Set newSet;int i;
		int size = currentSize + set.currentSize;
		newSet.init(size);
		for ( i=0 ; i < currentSize ; i++)
			newSet.data [ newSet.currentSize++ ] = data [i];
		for ( i=0 ; i < set.currentSize ; i++)
			newSet.add (set.data[i]);
		return newSet;
	}
	Set difference (const Set &set){
	    Set newSet;int i;
		int iterationsize = currentSize + set.currentSize;
		int size = currentSize;
		newSet.init(size);
		for ( i=0 ; i < size ;i++)
		if(!(set.isExist(data[i])))
			newSet.data [ newSet.currentSize++ ] = data [i];
		return newSet;
	}
	void print() const{
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
	int set1[5] = {5,10,15,20,25};
	int set2[5] = {10,20,30,40,50};
	s1.init(5);s2.init(5);
	for(int i = 0;i<5;i++){
		s1.add(set1[i]);
		s2.add(set2[i]);
		}
	cout << "Set1: ";s1.print();
	cout << "Set2: ";s2.print();
	cout <<'\n'<<"1 if 10 is in set1: "<<s1.isExist(10)<<'\n';
	cout <<"Set1 Union Set2 :";s1._union(s2).print();
	cout <<"Set1 Intersection Set2 :";s1.intersection(s2).print();
	cout <<"Set1 Difference Set2 :";s1.difference(s2).print();
	s1.resize(10);
	for(int i=25;s1.currentSize<s1.size;){
	if(s1.add(i+8))i++;
	}
	cout << "New Set1: ";s1.print();
	s1.free();
	s2.free();
	
	
	return 0;
}
