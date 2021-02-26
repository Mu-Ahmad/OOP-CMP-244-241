#include <iostream>

using namespace std;

int divide(int &x, int &y){
	if (y==0)	throw(5);
	return x/y;
}
void printSequence(int x, int y){
	if (y<x)	throw "Invalid Range\n";
	for (int i=x;i<=y;i++)
		cout << i << ' ';
	cout << '\n';
}
int main(){
	int x, y;
	try{
		cin >> x >> y;
		cout << divide (x, y)<< '\n';
		printSequence(3,7);
		printSequence(3,2);
	}catch(int a){
		cout << "Y is Zero\n" ;
	}catch(const char *c){
		cout << c ;
	}
}
