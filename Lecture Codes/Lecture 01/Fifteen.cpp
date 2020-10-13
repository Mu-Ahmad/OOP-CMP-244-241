#include <iostream>

using namespace std;

int main(){
	int *x, count, i ;
	cout << "Enter No of values:";  	
	cin >> count;

	x = new int[count];  //alternate malloc
	
	for (i=0;i<count;i++){
		x[i]=rand()%100;
		cout << x[i] << '\n';
	}
	delete []x;  //altrnate free
	return 0;
}

