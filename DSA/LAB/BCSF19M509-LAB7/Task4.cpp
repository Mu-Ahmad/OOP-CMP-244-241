/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>
#include <cmath>
#include "Stack.cpp"

using namespace std;


void divide(int n) {
	Stack<int> stack(n * 2);
	bool isDoneAlready[n] = {0};
	stack.push(n);
	int number;
	while (!stack.isEmpty()) {
		number = stack.pop();
		if (number < 2) continue;
		if (!isDoneAlready[number]) {
			isDoneAlready[number] = true;
			cout << number << ": " << ceil(number / 2.0) << " + " << number / 2 << '\n';
			stack.push(number / 2);
			stack.push(ceil(number / 2.0));
		}
	}
	return;
}



int main() {
	cout << "---------------------------divide(37)-------------------------\n";
	divide(37);
	cout << "---------------------------divide(32)-------------------------\n";
	divide(32);
	// uncomment following to read input
	// int n;
	// cout << "\nEnter Number: ";
	// cin >> n;
	// divide(n);
	return 0;
}
