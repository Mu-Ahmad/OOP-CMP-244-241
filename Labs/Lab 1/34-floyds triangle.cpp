#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num, i, j, a = 1;
    cin >> num;
    for (i = num ; i >= 1 ; i--)
    {
        for (j = 1 ; j <= i ; j++)
        {
            cout << a << " ";
            a++;
        }
        cout << '\n';
    }
    return 0;
}

