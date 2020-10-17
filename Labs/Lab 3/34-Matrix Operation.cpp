#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int rows, cols, total_op, curr_op, i, j, a = 1, kthrow, kthcol, jthrow, jthcol, scalar;
    cin >> rows >> cols;
    int matrix[rows][cols];
    for (i = 0 ; i < rows ; i++) {
        for (j = 0 ; j < cols ; j++) {
            cin >> matrix[i][j];
        }
    }
    cin >> total_op;
    while (a <= total_op) {
        cin >> curr_op;
        if (curr_op == 1) {
            cin >> kthrow >> scalar;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (i == kthrow-1) {
                        matrix[kthrow-1][j] *= scalar;
                    }
                }
            }
            a++;
        }
        else if (curr_op == 2) {
            cin >> kthcol >> scalar;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (j == kthcol-1) {
                        matrix[i][kthcol-1] *= scalar;
                    }
                }
            }
            a++;
        }
        else if (curr_op == 3) {
            cin >> jthrow >> kthrow;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (i == kthrow-1) {
                        matrix[kthrow-1][j] += matrix[jthrow-1][j];
                    }
                }
            }
            a++;
        }
        else if (curr_op == 4) {
            cin >> jthcol >> kthcol;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (j == kthcol-1) {
                        matrix[i][kthcol-1] += matrix[i][jthcol-1];
                    }
                }
            }
            a++;
        }
        else if (curr_op == 5) {
            cin >> jthrow >> kthrow;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (i == kthrow-1) {
                        matrix[kthrow-1][j] -= matrix[jthrow-1][j];
                    }
                }
            }
            a++;
        }
        else if (curr_op == 6) {
            cin >> jthcol >> kthcol;
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    if (j == kthcol-1) {
                        matrix[i][kthcol-1] -= matrix[i][jthcol-1];
                    }
                }
            }
            a++;
        }
        else if (curr_op == 7) {
            for (i = 0 ; i < rows ; i++) {
                for (j = 0 ; j < cols ; j++) {
                    cout << matrix[i][j] << ' ';
            }
                cout << '\n';
                }
             a++;
            }
        }
    return 0;
}

