#include <iostream>
#include "Magazine.cpp"

using namespace std;

int main(){
	string title="ABC";
	string author="DEF";
	int price=1000;
	string no="June 2020";
	Magazine m(title, author, price, no);
	cout << m;
	return 0;
}

