#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int x;
	cout << "Enter any value:";
	cin >> x ;
	cout << "Value entered is:" << setw(5) << x << "***\n";
	return 0;
}

