#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Set {
    private:
        int size;
        int cur_size;
        char *set;
        void copy(const Set &a) {
            int i;
            size = a.size;
            cur_size = a.cur_size;
            set = new char [cur_size];
            for (i = 0 ; i < cur_size ; i++) {
                set[i] = a.set[i];
            }
        }
        void freeMemory() {
            delete []set;
        }
        bool isExist(const char elem) const{
            int i;
            for (i = 0 ; i < cur_size ; i++) {
                if (set[i] == elem) {
                    return true;
                }
            }
            return false;
        }
    public:
        Set (int size = 5) {
            this->size = size;
            cur_size = 0;
            set = new char [size];
        }
        Set (const Set &a) {
            copy(a);
        }
        void operator = (const Set &a) {
            freeMemory();
            copy(a);
        }
        Set operator + (const Set &a){
            Set uniion (size + a.size);
            int i, j;
            for (i = 0 ; i < cur_size;i++) {
                uniion.set[uniion.cur_size++] = set[i];  
            }
            for (j = 0 ; j < a.cur_size ; j++) {
                if (!uniion.isExist(a.set[j])) {
                    uniion.set[uniion.cur_size++] = a.set[j];
                }
            }
        return uniion;
        }
        void operator * (const Set &a) {
            int i, j;
            cout << '{';
            for(i = 0; i < cur_size; i++)
            {
                for(j = 0; j < a.cur_size; j++)
                {
                    cout<<'(' << set[i] << ',' << a.set[j] << ')';
                    if(i == cur_size-1 && j == a.cur_size-1)
                    break;
                    cout<<',';
                }
            }
            cout<<'}';
            cout<<'\n';

        }
        Set operator - (const Set &a) {
            Set diff (size);
            int i;
            for (i = 0 ; i < cur_size ; i++) {
                if (!(a.isExist(this->set[i]))){
                    diff.set[diff.cur_size++] = set[i];
                }
            }
            return diff;
        }
        bool operator + (const char elem){
            if (cur_size == size) {
                return false;
            }    
            else if (isExist(elem)) {
                return false;
            }      
            set[cur_size++] = elem;
            return true;
        }
        void operator - (const char elem) {
            int i, flag, x = 0;
            for (i = 0 ; i < cur_size ; i++) {
                if (set[i] == elem) {
                    cur_size -= 1;
                    flag = 1;
                    x = i;
                }
            }
            for (i = x ; i < cur_size ; i++) {
                if (flag) {
                    set[i] = set[i + 1];
                }
            }
        }
        bool operator == (const Set &a) {
            int i, j, x = 0;
            for (i = 0 ; i < cur_size ; i++) {
                for (j = 0 ; j < a.cur_size ; j++) {
                    if (set[i] == a.set[j]) {
                        x++;
                    }
                }
            }
            if (x == cur_size) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator != (const Set &a) {
            int i, j, x = 0;
            for (i = 0 ; i < cur_size ; i++) {
                for (j = 0 ; j < a.cur_size ; j++) {
                    if (set[i] == a.set[j]) {
                        x++;
                    }
                }
            }
            if (x == cur_size) {
                return false;
            }
            else {
                return true;
            }
        }
        ~Set() {
            freeMemory();
        }
        friend ostream& operator << (ostream &print, Set &a);
};

ostream& operator << (ostream &print, Set &a){
    int i;
    if (a.cur_size == 0) {
        print << "EMPTY SET";
    }
    else {
        for (i = 0 ; i < a.cur_size ; i++) {
        print << a.set[i] << ' ';
        }
    }
    print << '\n';
    return print;
}    

int main() {
    Set s[5];
    int nOp, e = 1, opNum, set1, set2, set, numElem, i, result;
    char c, el;
    cin >> nOp;
    while (e <= nOp) {
        cin >> opNum;
        switch(opNum) {
            case 1:
                cin >> set1 >> set2 >> result;
                s[result - 1] = s[set1 - 1] + s[set2 - 1];
                break;
            case 2:
                cin >> set1 >> set2;
                s[set1 - 1] * s[set2 - 1];
                break;
            case 3:
                cin >> set1 >> set2 >> result;
                 s[result - 1] = s[set1 - 1] - s[set2 - 1];
                break;
            case 4:
                cin >> set >> c;
                s[set - 1] + c;
                break;
            case 5:
                cin >> set >> c;
                s[set - 1] - c;
                break;
            case 6:
                cin >> set1 >> set2;
                if (s[set1 - 1] == s[set2 - 1]) {
                    cout << "TRUE\n";
                }
                else {
                    cout << "FALSE\n";
                }
                break;
            case 7:
                cin >> set1 >> set2;
                if (s[set1 - 1] != s[set2 - 1]) {
                    cout << "TRUE\n";
                }
                else {
                    cout << "FALSE\n";
                }
                break;
            case 8:
                cin >> set;
                cout << s[set - 1];
                break;
            case 9:
                cin >> set >> numElem;
                for (i = 0 ; i < numElem; i++){
                    cin >> el;
                    s[set - 1] + el;
                }
                break;
            case 10:
                cin >> set1 >> set2;
                s[set1 - 1] = s[set2 - 1];
                break;
        }
        e++;
    }
    return 0;
}
