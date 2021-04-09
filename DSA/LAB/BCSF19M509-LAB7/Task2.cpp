/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>
#include <cmath>
#include "Stack.cpp"

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int nextPrime(int number) {
	for (int i = number + 1; i < pow(2, 31) - 1; i++)
		if (isPrime(i)) return i;
	return -1;
}

void divisor(int n) {
	Stack<int> stack(n);
	stack.push(n);
	while (!stack.isEmpty()) {
		n = stack.pop();
		if (isPrime(n))
			continue;
		// Number is definitely a composite
		int prime = 2;
		while (n % prime)
			prime = nextPrime(prime);
		cout << "Divisor of " << n << " : " << prime;
		if (prime == n / prime) cout << '\n';
		else cout << " , " << n / prime << '\n';

		stack.push(n / prime);
	}
}


int main() {
	cout << "---------------------------divisor(16)-------------------------\n";
	divisor(16);
	cout << "---------------------------divisor(64)-------------------------\n";
	divisor(64);
	cout << "---------------------------divisor(49)-------------------------\n";
	divisor(49);
	// uncomment following to read input
	// int n;
	// cout << "\nEnter Number: ";
	// cin >> n;
	// divisor(n);
	return 0;
}
