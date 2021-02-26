#include <iostream>

using namespace std;

int main(){
	int x[10000000000];	
	cout << x[-1] << ' ' << x[0] << ' ' << x[1] << ' ' << x[15] << '\n';
	return 0;
}
