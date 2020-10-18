#include <iostream>
using namespace std;
int factorial(int n) {
    if (n > 1) return n * factorial(n - 1);
}int main() {
    int n, result;
    cout << "Enter a number: ";
    cin >> n;
    result = (n==1) ? 1: factorial(n);
    cout << result;
    return 0;
}