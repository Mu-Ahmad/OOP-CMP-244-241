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
	int x;
	A a;//Strong aggregation
public:
	B(int x){	this->x=x; cout << "Object of B is created with value " << x << '\n';}
	~B(){	cout << "Object of B is removed with value " << x << '\n';}

};
void fazoolFunction(){
	B objB(2);
}
int main(){
	B objB(1);
	cout << "\nOne object of B & A is created\n";
	fazoolFunction();
	cout << "\nAnother object of B & A is created inside function and deleted after the function call\n";
	cout << "\nObject created in main still exist\n";
	return 0;

}
