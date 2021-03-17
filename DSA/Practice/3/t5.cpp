/*
Write a recursive function to add the first n terms of the series:
n = 6: 1 + 1/2 + 1/3 + 1/4 + 1/5 + 1/6 = 2.45
*/

#include<iostream>
#include <string>

using namespace std;
double seriesSum(int n){
	if(n == 1) return 1;
	return 1.0/n + seriesSum(n-1);
}
int main(int args, char** argv){
	cout << seriesSum(6);
	cout << "\nDone with this program.\n";
	return 0;
}