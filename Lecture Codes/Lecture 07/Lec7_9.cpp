#include <iostream>

using namespace std;

void show(int x[], const int SIZE){
	for (int i=0;i<SIZE;i++)
		cout << x[i] << ' ';
	cout << '\n';
}
int main(){
	int x[]={3,7,5,8,9};
	int y[5];
	for (int i=0;i<5;i++)
		y[i] = x[i];	
	y[2] = 10;
	show (y, 5);
	show (x,5);
	int *z = x;
	z[2]=20;
	show (z, 5);
	show (x, 5);
	return 0;
}
