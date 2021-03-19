#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size, x, low, high, mid, key;
    bool found;
    cin >> size; 
    vector <int> v, v1;
    for (int i = 0 ; i < size ; i++) {
        cin >> x;         // 23 5 45 87 35 v1
        v.push_back(x);
        v1.push_back(x);  // 5 23 35 45 87 v
    }
    sort(v.begin(), v.end());
    for (int i = 0 ; i < size ; i++) {
        found = false;
        low = 0;
        high = size - 1;
        key = v1[i];
        while ((!found) && (low <= high)) {
            mid = (low + high) / 2;
            if (v[mid] == key) {
                found = true;
                cout << mid + 1 << ' ';
            }
            else if (v[mid] > key) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
    }
    return 0;
}

