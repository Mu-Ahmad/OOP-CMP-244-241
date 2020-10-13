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
	int *y = x;
	show (y, 5);
	return 0;
}
