#include <iostream>
#include <ctime>

using namespace std;

//const data members. Such data members can be initialized once for any individual object.
//Constant data members are initialized before the constructor body


class ABC{
	const int SIZE;	
public:
	ABC (int size):	SIZE(size){
		SIZE = size;
	}
	/*void setSIZE(int newSize){
		SIZE = newSize;
	}*/
	int getSIZE() const{
		return SIZE;
	}	
};


int main(){
	ABC abc1(30), abc2(50);
	cout << abc1.getSIZE() << '\n';
	cout << abc2.getSIZE() << '\n';
	//abc1.setSIZE(40);
	return 0;
}
