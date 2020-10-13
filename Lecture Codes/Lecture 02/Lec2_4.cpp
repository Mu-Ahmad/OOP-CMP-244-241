#include <iostream>
#include <ctime>

using namespace std;

void initRandom(int *a[5], const int SIZE){
    int i,j;
    for (i=0;i<5;i++)
        for (j=0;j<SIZE;j++)
            a[i][j]=rand()%100;
}

void print(int *a[5], const int SIZE){
    int i,j;
    for (i=0;i<5;i++){
        for (j=0;j<SIZE;j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
}
int main() {
    srand(time(0));
    int *a[5], col_size, i;
    cout<<"Enter Column Size:";
    cin>>col_size;
    for (i=0;i<5;i++)
        a[i] = new int [col_size];
    
    initRandom(a, col_size);
    print(a, col_size);
    
    for (i=0;i<5;i++)
        delete []a[i];
    return 0;
}
