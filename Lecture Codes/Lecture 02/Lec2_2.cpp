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
    int *array, count, i;
    cout<<"Enter Count:";
    cin>>count;
    array = new int[count];
    initRandom(array, count);
    print(array, count);
    insertionSort(array, count);
    print(array, count);
    delete []array;
    return 0;
}
