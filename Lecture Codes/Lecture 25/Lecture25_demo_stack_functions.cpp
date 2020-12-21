#include <iostream>

using namespace std;

void f1(){
	cout << "F1 is called\n";
}
void f2(){
	cout << "F2 is calling F1\n";	
	f1();//function call includes hidden instruction push
	cout << "F2: Back from F1\n";	
	//return includes hidden instruction pop
}
void f3(){
	cout << "F3 is calling F2\n";	
	f2();
	cout << "F3: Back from F2\n";	
}
void f4(){
	cout << "F4 is calling F3\n";	
	f3();
	cout << "F4: Back from F3\n";	
}

int main(){
	cout << "Main function is calling F4\n";	
	f4();
	cout << "Main: Back from F4\n";	
	return 0;	
}
