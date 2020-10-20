#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Set{
	int size, cSize, *e;
	bool isExist(const int ELEMENT){
		for (int i=0;i<cSize;i++)
			if (e[i]==ELEMENT)
				return true;
		return false;
	}
public:
	Set(int size=10){
		this->size = size;
		cSize = 0;
		e = new int[size];
	}
	bool operator + (const int ELEMENT){
		if (cSize==size)		return false;
		if (isExist(ELEMENT))	return false;	
		e[cSize++] = ELEMENT;
	}
	Set operator + (const Set &s){
		Set newSet(size+s.size);
		int i, j;
		for (i=0;i<cSize;i++)
			newSet.e[newSet.cSize++] = e[i];
		for (j=0;j<s.cSize;j++)
			if (!newSet.isExist(s.e[j]))
				newSet.e[newSet.cSize++] = s.e[j];
		return newSet;
	}	
	void show() const{
		for (int i=0;i<cSize;i++)
			cout << e[i] << ' ';
		cout << '\n';
	}
	~Set(){
		delete []e;
	}	
};

int main(){
	Set s1(5);
	s1 + 3;
	s1 + 5;
	s1 + 7;
	s1 + 3;
	s1.show();
	cout << "--------------\n";
	Set s2(5);
	s2 + 2;
	s2 + 6;
	s2 + 7;
	s2 + 4;
	s2.show();
	cout << "--------------\n";
	Set s3 = s1 + s2;
	s3.show();
	return 0;
}
