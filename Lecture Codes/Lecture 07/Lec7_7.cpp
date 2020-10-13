#include <iostream>

using namespace std;

void show(int x[], const int SIZE){
	for (int i=0;i<SIZE;i++)
		cout << x[i] << ' ';
	cout << '\n';
}
int main(){
	int x[]={3,7,5,8,9};
	show (x,5);
	int y[5];
	for (int i=0;i<5;i++)
		y[i] = x[i];	
	show (y, 5);
	int *z = x;
	show (z, 5);
	return 0;
}
