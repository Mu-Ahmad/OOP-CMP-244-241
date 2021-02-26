#include <iostream>

using namespace std;

int main(){
	int i=0;
	while (i != -1){
		cout << "Enter a number (-1 to exit): ";
		cin >> i;
		if (cin.fail()){//Error flag  
			cout << "Not a valid number!\n";
			cin.clear();   
			cin.ignore(2);//number of characters or delim character
		}
		else if (i != 1)
			cout << "The number is: " << i << '\n';
	}
	return 0;
}
