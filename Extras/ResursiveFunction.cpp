#include <iostream>
using namespace std;

long double factorial(int n) {
          if (n <= 1) // base case
        return 1;
    else    
        return n*factorial(n-1);   
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

