#include <iostream>

using namespace std;

class Set{
	int *d, currentSize, size;
public:
	Set(int s){
		size = s;
		currentSize = 0;
		d = new int[size];
	}
	//Copy constructor creating deep copy
	Set(const Set &s){
		size = s.size;
		currentSize = s.currentSize;
		d = new int[size];
		for (int i=0;i<currentSize;i++)		
			d[i] = s.d[i];
	}
	bool isExist(const int ELEMENT){
		for (int i=0;i<currentSize;i++)
			if (d[i] == ELEMENT)
				return true;
		return false;
	}
	bool add(const int ELEMENT){
		if (currentSize == size)	return false;
		if (isExist(ELEMENT))		return false;
		d[currentSize++] = ELEMENT; 
		return true;
	}
	void show() const{
		for (int i=0;i<currentSize;i++)
			cout << d[i] << ' ';
		cout << '\n';
	}
};
int main(){
	Set s1(5);
	s1.add(3);
	s1.add(6);
	s1.add(8);
	Set s2 = s1;//Deep copy
	s1.show();
	s2.show();
	s2.add(9);
	s1.add(2);
	s1.show();
	s2.show();
	return 0;
}
