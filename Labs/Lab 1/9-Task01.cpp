#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int power = pow(i, i);
        s = s + power;
        cout << power << " ";
    }
    cout << s ;
    return 0;
}