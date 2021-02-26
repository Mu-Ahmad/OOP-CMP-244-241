#include <iostream>

using namespace std;

int main(){
	int i=0,sum=0,n=0;
	while (i != -1){
		cout << "Enter a number (-1 to exit): ";
		cin >> i;
		if (i != 1){
			cout << "The number is: " << i << '\n';
			sum=sum+i;
			n++;
		}
	}
	cout << sum / n;
	return 0;
}