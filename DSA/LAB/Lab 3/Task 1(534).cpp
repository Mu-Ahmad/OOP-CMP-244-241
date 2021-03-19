#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int Compute(vector <int> v, int s, int i, int sum, int g1, int g2, int diff, int ans) {
    if (i == s) {
        return ans;
    }
    g1 += v[i];
    g2 = sum - g1;
    if (diff > abs(g1 - g2)) {
        ans = i + 1;
        diff = abs(g1 - g2);
    }    
    return Compute(v, s, i + 1, sum, g1, g2, diff, ans);
}

int main() {
    int size, n, sum, g1, g2, diff;
    cin >> size;
    vector <int> vec;
    for (int i = 0 ; i < size ; i++) {
        cin >> n;
        vec.push_back(n);
    }
    sum = accumulate(vec.begin(), vec.end(), 0);
    g1 = vec[0];
    g2 = sum - g1;
    diff = abs(g1 - g2);  
    cout << Compute(vec, size, 1, sum, g1, g2, diff, 0);
    return 0;
}
