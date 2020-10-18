#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int num, i, sum = 0;
    cin >> num;
    for (i = 1 ; i <= num ; i++)
    {
        int ans = pow(i, i);
        sum += ans;
        cout << ans << " ";
    }
    cout << sum;
    return 0;
}

