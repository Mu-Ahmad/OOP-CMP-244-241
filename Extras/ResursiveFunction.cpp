#include <iostream>
using namespace std;

long double factorial(int n) {
         return (n <= 1) ? 1 : n*factorial(n-1); 
}

int main() {
            int n;
	    long double result;
            cout << "Enter a number: ";
            cin >> n;
            result = factorial(n);
            cout << result;
            return 0;
}

