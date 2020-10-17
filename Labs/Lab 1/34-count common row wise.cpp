#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int row_size, col_size1, col_size2, **a, **b, i, j, k, x, y, z;
    cin >> row_size;
    cin >> col_size1;
    cin >> col_size2;
    a = new int* [row_size];
    for (i = 0 ; i < row_size ; i++)
    {
        a[i] = new int [col_size1];
    }
    b = new int* [row_size];
    for (i = 0 ; i < row_size ; i++)
    {
        b[i] = new int [col_size2];
    }    
    for (i = 0 ; i < row_size ; i++)
    {
        for (j = 0 ; j < col_size1 ; j++)
        {
            cin >> a[i][j];
        }
    }
    for (i = 0 ; i < row_size ; i++)
    {
        for (j = 0 ; j < col_size2 ; j++)
        {
            cin >> b[i][j];
        }
    }
    for (x = 0 ; x < row_size ; x++)
    {
        int count = 0;
        for (y = 0 ; y < col_size1 ; y++)
        {
            for (z = 0 ; z < col_size2 ; z++)
            {
                if (a[x][y] == b[x][z])
                {
                    count++;
                }
            }
        }
         cout << count << '\n';
    }
}

