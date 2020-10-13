#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int i=1;
	for (i=1;i<=20;i++)
		cout << setw(5) << i << "*****" << setw(5) << i << '\n' ;


	return 0;
}

