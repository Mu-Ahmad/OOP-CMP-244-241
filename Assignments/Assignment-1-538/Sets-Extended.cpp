#include <iostream>
#include <algorithm>  
#include <vector> 
using namespace std;

struct Set{
	int *data, currentSize, size;
	int *UniversalSet;
	int uniarraysize;
	void init (const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	   }
	   
	void uniset (const int SIZE){
	    uniarraysize = SIZE;
		UniversalSet = new int[SIZE];
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
	
	Set unionFunction (const Set &set){
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
	
	Set complement (){
	    Set newSet;int i;
		int iterationsize = uniarraysize;
		newSet.init(iterationsize);
		for ( i=0 ; i < iterationsize ;i++)
		if(!(isExist(UniversalSet[i])))
			newSet.data [ newSet.currentSize++ ] = UniversalSet[i];
		return newSet;
	}
	
	bool isProperSubset (const Set &set){
	    int i,count=0;
		int iterationsize = currentSize;
		for ( i=0 ; i < iterationsize ;i++)if(set.isExist(data[i]))
			count++;
		if(count == currentSize && currentSize < set.currentSize)
		return true;
		else
		return false;
	}
	
	bool isSubset (const Set &set){
	    int i,count=0;
		int iterationsize = set.currentSize;
		int size = currentSize;
		for ( i=0 ; i < iterationsize ;i++)
		if(set.isExist(data[i]))
			count++;
		if(count == currentSize && count ==set.currentSize) return true;
		                            else	              	return false;
	}
	
	void resize (const int newSize){
        if(newSize <=0 && newSize !=size){   
        int newarray[currentSize];
        for(int i=0;i<currentSize;i++)
        newarray[i] = data[i];
        delete []data;
        size = newSize;
    	data = new int[newSize];
    	for(int i=0;i<currentSize;i++)
        data[i] = newarray[i];
	}
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

	struct Set s1, s2,s3,s4;
	int set1[5] = {5,10,15,20,25};
	int set2[5] = {10,20,30,40,50};
	int set3[5] = {5,10,15,20,2};
	int set4[6] = {5,10,15,20,25,-1};
	
	s1.init(5);s2.init(5);s3.init(5);s4.init(6);
	for(int i = 0;i<5;i++){
		s1.add(set1[i]);
		s2.add(set2[i]);
		s3.add(set3[i]);
		s4.add(set4[i]);
		
	}
	s4.add(set4[5]);
	cout << "Set1: ";
	s1.print();
	cout << "Set2: ";
	s2.print();
	cout << "Set3: ";
	s3.print();
	cout << "Set4: ";
	s4.print();
	cout <<'\n'<<"1 if 10 is in set1: "<<s1.isExist(10)<<'\n';
	cout <<"Set1 Union Set2 :";s1.unionFunction(s2).print();
	cout <<"Set1 Intersection Set2 :";s1.intersection(s2).print();
	cout <<"Set1 Difference Set2 :";s1.difference(s2).print();
	cout<<"Set1 is subset of Set3:  "<< s1.isSubset(s3);
	cout<<'\n';
	cout<<"Set1 is Propersubset of Set4: " <<s1.isProperSubset(s4);
	cout<<'\n';
	s1.resize(10);
	for(int i=25;s1.currentSize<s1.size;){
	if(s1.add(i+8))i++;
	}
	cout << "New Set1: ";s1.print();
	int universalsize,i;
    cout<< "Enter Universal set size:";
	cin>>universalsize;
	s1.uniset(universalsize);
    cout<< "Enter Universal set Elements:";
    for(i=0;i<universalsize;i++)
	cin>>s1.UniversalSet[i];
    cout<<"Set1 Complement: ";s1.complement().print();
    s1.free();
	s2.free();
	s3.free();
	s4.free();
	
	return 0;
}
