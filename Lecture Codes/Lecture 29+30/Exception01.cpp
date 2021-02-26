#include <iostream>

using namespace std;

int divide(int &x, int &y){
	if (y<0)	throw(0);
	if (y==0)	throw(1);
	return x/y;
}
int main(){
	int x, y;
	try{
		cin >> x >> y;
		cout << divide (x, y)<< '\n';
		
	}catch(int a){
		if (a==0)	cout << "Y is Negative\n" ;
		if (a==1)	cout << "Y is Zero\n" ;
	}
	cout << "Program is going to terminate\n";
	return 0;
}
