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
	void show() const{
		for (int i=0;i<cSize;i++)
			cout << e[i] << ' ';
		cout << '\n';
	}
};

int main(){
	Set s1(5);
	s1 + 3;
	s1 + 5;
	s1 + 7;
	s1 + 3;
	s1.show();
	return 0;
}
