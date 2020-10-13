#include <iostream>

using namespace std;

class Test{
	int i;
public:
	Test(int vi){ 	
		i = vi;
		cout << "Object " << i << " created\n"; 
	}
	~Test(){ cout << "Object " << i << " destroyed\n";}
};
void f1(){
	Test t(1);
	cout << "Function f1 is going to finish, so object inside f1 is going to destroy\n";
}	
void f2(){	
	Test t(2);
	f1();
	cout << "Function f2 is going to finish, so object inside f2 is going to destroy\n";
}
	
int main(){
	Test t(3);
	f2();
	cout << "Main is going to finish, so object inside main is going to destroy\n";
	return 0;
}
