#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Bag {
    int *a, current_size, max_size;
    void set(const int SIZE) {
        max_size = SIZE;
        current_size = 0;
        a = new int [max_size];
    }
    bool add(const int ELEM) {
        if (current_size == max_size) {
            return false;
        }
        a[current_size++] = ELEM;
        return true;
    }
    void insert(const int ELEMENT, const int index) {
        int i, j;
        for(i = 0 ; i < max_size ; i++)
            if(i == index)
                for(j = max_size ; j > i ; j--) {
                    a[j] = a[j - 1]; 
                }  
        a[index] = ELEMENT;
        current_size = current_size + 1;
    }
    void remove(const int ELEM) {
        int i, j;
        for(i = 0 ; i < current_size ; i++) {
            if(a[i] == ELEM)  {
                current_size--;
                for(j = i ; j < current_size ; j++) {
                    a[j] = a[j + 1];
                }
            }
        }
    }
    void print() {
        int i;
        if (current_size == 0 ) {
            cout << "Empty Set";
        }
        for (i = 0 ; i < current_size ; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    void free() {
        delete []a;
    }
};

int main() { 
    struct Bag bag;
    int max, n, i, num, rem, ins, indx;
    cin >> max;
    cin >> n;
    bag.set(max);
    for(i = 0 ; i < n ; i++)
    {
        cin >> num;
        bag.add(num);
    }
    cin >> rem;
    cin >> ins;
    cin >> indx;
    bag.print();
    bag.remove(rem);
    bag.print();
    bag.insert(ins, indx);
    bag.print();
    bag.free();
    return 0;
}

