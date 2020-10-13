#include <iostream>
#include <ctime>

using namespace std;

void initRandom(int **a, const int ROWSIZE, const int COLSIZE){
    int i,j;
    for (i=0;i<ROWSIZE;i++)
        for (j=0;j<COLSIZE;j++)
            a[i][j]=rand()%100;
}

void print(int **a, const int ROWSIZE, const int COLSIZE){
    int i,j;
    for (i=0;i<ROWSIZE;i++){
        for (j=0;j<COLSIZE;j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}

int main() {
    srand(time(0));
    int **a, row_size, col_size, i;
    cout<<"Enter Row Size:";
    cin>>row_size;
    cout<<"Enter Column Size:";
    cin>>col_size;
    a = new int* [row_size];
    for (i=0;i<row_size;i++)
        a[i] = new int [col_size];
    
    initRandom(a, row_size, col_size);
    print(a, row_size, col_size);
    
    for (i=0;i<5;i++)
        delete []a[i];  //deleting rows
    delete []a;         //deleting 1D pointers
    return 0;
}
