#include<iostream>
#include<vector>

using namespace std;

int main() {
    int row, col1, col2; cin >> row >> col1 >> col2;
    int arr1[row][col1];
    int arr2[row][col2];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> arr1[i][j];
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col2; j++)
            cin >> arr2[i][j];
    }
    for (int n = 0; n < row; n++) {
        int count = 0;
        for (int i = 0; i < col1; i++)
            for (int j = 0; j < col2; j++)
                if (arr1[n][i] == arr2[n][j]) {
                    count++;
                    break;
                }
        cout << count << '\n';
    }
    return 0;
}