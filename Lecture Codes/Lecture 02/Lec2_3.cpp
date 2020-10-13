#include <iostream>
#include <ctime>

using namespace std;

void initRandom(int *a, const int SIZE){
    for (int i=0;i<SIZE;i++)
        a[i]=rand()%100;
}

void print(int *a, const int SIZE){
    for (int i=0;i<SIZE;i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void insertionSort(int *a, const int SIZE){
    int i, j, temp;
    for (i=1;i<SIZE;i++){
        temp = a[i];
        for (j=i-1;j>=0 && a[j]>temp;j--)
            a[j+1] = a[j];
        a[j+1] = temp;
    }
}

int main() {
    srand(time(0));
    int *a[5], col_size, i;
    cout<<"Enter Column Size:";
    cin>>col_size;
    for (i=0;i<5;i++){
        a[i] = new int [col_size];
        initRandom(a[i], col_size);
        print(a[i], col_size);
    }
    for (i=0;i<5;i++)
        delete []a[i];
    return 0;
}
