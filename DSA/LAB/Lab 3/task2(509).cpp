#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

bitset<1000> Isprime;
void primeSieve(bitset<1000>& arr, int n) {
	for (int i = 3; i <= n; i += 2) {
		arr[i] = 1;
	}
	for (long long i = 3; i <= n; i += 2) {
		if (arr[i]) {
			for (long long j = i * i; j < n; j += i) {
				arr[j] = 0;
			}
		}
	}
	arr[0] = arr[1] = 0;
	arr[2] = 1;
}

// Helper function to grab next prime, given a number
int nextPrime(int curr) {
	for (int i = curr + 1; i < 10000001; i++)
		if (Isprime[i]) return i;

	return -1;
}

// Helper log function
double log0f(int val, int base) {
	return log(val) / log(base);
}

void Magic(int n, int prime) {
	// Base Case
	if (n < prime) {
		(n) ? cout << n << '\n' : cout << '\n';
		return;
	}
	// Recursive Case
	int exponent = floor(log0f(n, prime));
	cout << prime << ' ' << exponent << ' ';
	return Magic(n - (int)pow(prime, exponent), nextPrime(prime));
}

int main() {
	primeSieve(Isprime, 1000); // initiate the list of primes in first 1000 natural numbers
	int n; cin >> n;
	Magic(n, 2);
	return 0;
}

/*
“I do not intend to tiptoe through life to arrive safely at death.”

M.M. Gavillet
*/