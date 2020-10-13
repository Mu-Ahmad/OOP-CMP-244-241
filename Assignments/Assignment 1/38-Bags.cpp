#include <iostream>
#include <algorithm>  
#include <vector> 
using namespace std;

struct Bag{
	int *data, currentSize, size;
	
	void init (const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
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
	
	void add(const int ELEMENT){
		if (currentSize == size)cout<< "Bag is Full";
		else
		data [ currentSize++ ] = ELEMENT;
	}

	Bag merge (const Bag &bag){
	    Bag newBag;int i;
		int size = currentSize + bag.currentSize;
		newBag.init(size);
		for ( i=0 ; i < currentSize ; i++)
		newBag.data [ newBag.currentSize++ ] = data [i];
		for ( i=0 ; i < bag.currentSize ; i++)
		newBag.add(bag.data[i]);
		return newBag;
	}
	
	int indexOf (const int ELEMENT){
	
	for (int i=0;i<currentSize;i++)
			if (data[i] ==  ELEMENT)
				return i;
		return -1;
	
	}
	
	bool has (const Bag &bag){
		
	    int i,count=0;
		int iterationsize = bag.currentSize;
		for ( i=0 ; i < iterationsize ;i++)
		if(isExist(bag.data[i]))
			count++;
			if(count == bag.currentSize)
		return true;
		else
		return false;
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
	struct Bag bag1, bag2,bag3;
	bag1.init(5);
	bag2.init(5);
	
	for(int i = 0;i<5;i++){
		bag1.add(i);
	    bag2.add(i*2+1);
	}
    cout<<"Bag1: ";
	bag1.print();
    cout<<"\nBag2: ";
	bag2.print();
    
	cout << "isExist 4 in bag1: "<<bag1.isExist(4)<<" with index at:"<<bag1.indexOf(4)<<'\n';
    
	bag3 = bag1.merge(bag2);
    
	cout<<"Bag 3:";
	
	bag3.print();
	
	cout<<"\nBag1 has Bag2(1/0):"<<bag1.has(bag2);
	
	cout<<"\nBag3 has Bag2(1/0):"<<bag3.has(bag2);
	
	bag1.resize(10);
	
	for(int i=0;bag1.currentSize<bag1.size;i++)  bag1.add(i*2+1);
	
	cout << "\nNew Bag1: ";bag1.print();
	cout<<"\nNew Bag1 has Bag2(1/0):"<<bag1.has(bag2);
	
	
	bag1.free();
	bag2.free();
	bag3.free();
	
	
	
	return 0;
}
