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

int main() {
    srand(time(0));
    int *array, count, i;
    cout<<"Enter Count:";
    cin>>count;
    array = new int[count];
    initRandom(array, count);
    print(array, count);
    delete []array;
    return 0;
}
