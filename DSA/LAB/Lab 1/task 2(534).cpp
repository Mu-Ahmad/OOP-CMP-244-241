#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define NO_KEY -1
#define NO_SAME_SIZE -2
using namespace std;

class Collection {
    private:
        int *data;
        int size;
        int currentSize;
    public:
        Collection(int size = 1) {
            this->size = size;
            currentSize = 0; 
            data = new int [size];
        }
        Collection (int arr[], int size) {
            this->size = size;
            data = new int [size];
            for (int i = 0 ; i < size ; i++) {
                data[i] = arr[i];
            }
            currentSize = size;
        }
        int get_size() {
            return size;
        }
        void operator ++ (const int x) {
            if (x < 0) {
                data[currentSize++] = x;
            }
            else {
                data[currentSize++] = -1;
            }
        }
        Collection(Collection &c) {
            size = c.size;
            currentSize = c.currentSize;
            data = new int [size];
            for (int i = 0 ; i < currentSize ; i++) {
                data[i] = c.data[i];
            }
        }
        int countElement(int key) {
            int count = 0;
            bool flag = false;
            for (int i = 0 ; i < currentSize ; i++) {
                if (data[i] == key) {
                    count++;
                    flag = true;
                }
            }
            if (!flag) {
                throw NO_KEY;
            }
            return count;
        }
        void operator = (const Collection &c) {
            if (!(size == c.size)) {
                throw NO_SAME_SIZE;
            }
            for (int i = 0 ; i < currentSize ; i++) {
                data[i] = c.data[i];
            }
        }
        Collection operator + (const Collection &c) {
            Collection c1;
            if (!(size == c.size)) {
                throw NO_SAME_SIZE;
            }
            for(int i = 0 ; currentSize ; i++) {
                c1.size = size;
                c1.data[i] = data[i] + c.data[i];
            }
            return c1;
        }
        bool operator == (const Collection &c) {
            if (!(size == c.size)) {
                throw NO_SAME_SIZE;
            }
            for (int i = 0 ; i < size ; i++) {
                for (int j = 0 ; j < size ; j++) {
                    if (!(data[i] == c.data[j])) {
                        return false;
                    }
                }
            }
            return true;
        }
        ~Collection() {
            delete []data;
            data = NULL;
            currentSize = size = 0;
        }
    friend ostream& operator << (ostream& out, const Collection &c);
};

ostream& operator << (ostream& out, const Collection &c) {
    for (int i = 0 ; i < c.currentSize ; i++) {
        out << c.data[i] << ' ';
    }
    cout << '\n';
    return out;
}

int main() {
    try {
        int n, x;
        int *array;
        Collection *coll;
        cin >> n;
        while (n--) {
            int y;
            cin >> x;
            switch(x) {
                case 1:
                {
                    cin >> y;
                    coll = new Collection(y);
                    break;
                }
                case 2:
                    cin >> y;
                    coll->operator++(y);
                    break;
                case 3:
                    cout << *coll;
                    break;
                case 4:
                {    
                    cin >> y;
                    array = new int [y];
                    for (int i = 0 ; i < y ; i++) {
                        cin >> array[i];
                    }
                    coll = new Collection(array, y);
                    break;
                }   
                case 5:
                {
                    Collection c = *coll;
                    break;  
                }
                case 6:
                    delete coll;
                    break;
                case 7: 
                {
                    cin >> y;
                    int x = coll->countElement(y); 
                    cout << x << ' ';
                    break;
                }
                case 8:
                {
                    Collection c1(coll->get_size());
                    c1 = *coll;
                    break;
                }
                case 9:
                {
                    Collection c5(coll->get_size());
                    cout << c5 + *coll;
                    break;
                }
                case 10:
                {
                    Collection c3(coll->get_size());
                    if (c3 == *coll) {
                        cout << "Same";
                    }
                    else {
                        cout << "Diferent";
                    }
                    break;
                }
            }
        }
    }
    catch (int t) {
        if (t == NO_SAME_SIZE) {
            cout << "Size not same";
        } 
        else if (t == NO_KEY) {
            cout << "no key found";
        }
    }
    return 0;
}


/*6 

1 5 

2 -3 

2 -5 

2 6 

3 

6*/ 