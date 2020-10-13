#include <iostream>

using namespace std;

struct Set{
	int *data, currentSize, size;
	void set(const int SIZE){
		size = SIZE;
		currentSize = 0;
		data = new int[size];
	}
	bool isExist(const int ELEMENT){
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
	void show(){
		for (int i=0;i<currentSize;i++)
			cout << data[i] << ' ';
		cout << '\n';
	}
};

int main(){
	struct Set s;
	s.set(5);//size is set with value 10
	/*s.add(3);
	s.add(7);
	s.add(86);
	s.add(7);
	s.show();*/

	srand(time(0));
	int i, value;
	for (i=0;i<5; ){
		value = rand() % 10;
		cout << "Value:" << value <<'\n';
		if (s.add(value))	i++;
	}
	s.show();
	return 0;
}
