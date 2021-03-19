#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size, k, x, y;
    int **arr;
    cin >> size;
    if (size % 2 == 0 && size < 3) {
        return 0;
    }
    arr = new int* [size];
    for (int i = 0 ; i < size ; i++) {
        arr[i] = new int [size];
    }
    for(int i = 0 ; i < size ; i++) {
        for (int j = 0 ; j < size ; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> k;
    if (k < 1) {
        return 0;
    }
    int center = size / 2;
    while (k--) {
        cin >> y >> x;
        if ((center + y >= size) || (center + x >= size)) {
            cout << "INVALID INPUT\n";
        }
        else if ((center + y < size) && (center + x < size)) {
            cout << arr[(center - x)][(center + y)] << '\n';
        }
    }
    return 0;
}

