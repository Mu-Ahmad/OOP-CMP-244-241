#include <iostream>

using namespace std;

/******************************************************************************************************
Aggregation
Weak and Strong Aggregation
Strong aggregation (also called composition) shows strong relationship between two classes that means class A is always part of class B, whereas Weak aggregation is that class B has pointer of class A and object of class A may or may not exist all the time.

Car and Tyre has strong aggregation (Car will not work without tyres)
 
Car and Car_AC has weak aggregation (car will work without AC)

Being designer of class, one has to decide whether to keep strong aggregation or weak aggregation

******************************************************************************************************/
class A{
public:
	A(){	cout << "Object of A is created\n";}
	~A(){	cout << "Object of A is removed\n";}
};

class B{
	A a;//Strong aggregation
public:
	B(){	cout << "Object of B is created\n";}
	~B(){	cout << "Object of B is removed\n";}

};
int main(){
	B objB;
	return 0;
}
