#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

int main() {
    int n, t, a, b;
    cin >> n;
    int a1[n], a2[n], a3[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> a1[i];
        cin >> a2[i];
        cin >> a3[i];
    }
    cin >> t;
    while (t--) {
        cin >> a >> b;
        switch(a) {
            case 0:
                for (int step = 0; step < n - 1; ++step) {
                    for (int i = 0; i < n - step - 1; ++i) {
                        if (a1[i] > a1[i + 1]) {
                            swap(&a1[i], &a1[i + 1]);
                            swap(&a2[i], &a2[i + 1]);
                            swap(&a3[i], &a3[i + 1]);
                        }
                    }
                }
                break;
                case 1:
                for (int step = 0; step < n - 1; ++step) {
                    for (int i = 0; i < n - step - 1; ++i) {
                        if (a2[i] > a2[i + 1]) {
                            swap(&a1[i], &a1[i + 1]);
                            swap(&a2[i], &a2[i + 1]);
                            swap(&a3[i], &a3[i + 1]);
                        }
                    }
                }
                break;
                case 2:
                for (int step = 0; step < n - 1; ++step) {
                    for (int i = 0; i < n - step - 1; ++i) {
                        if (a3[i] > a3[i + 1]) {
                            swap(&a1[i], &a1[i + 1]);
                            swap(&a2[i], &a2[i + 1]);
                            swap(&a3[i], &a3[i + 1]);
                        }
                    }
                }
                break;
        }
        cout << a1[b] << ' ' << a2[b] << ' ' << a3[b] << '\n';
    }
    return 0;
}

