#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Set {
    char *data;
    int size, currentSize;
    void copyElements(Set const &s){ 
        size = s.size;
        currentSize = s.currentSize;
        data = new char[size];
        for ( int i = 0; i < currentSize; i++ )
            data[i] = s.data[i];
    }
    public:
    Set(int s=5){
        size = s;
        currentSize = 0;
        data = new char[size];
    }
    Set(const Set &s){
        copyElements(s);
    }
    Set operator = (const Set &s){
        delete []data;
        copyElements(s);
        return *this;
    }
    bool isExist ( const char ELEMENT ) const {
        int i;
        for ( i = 0; i < currentSize; i++)
            if(ELEMENT == data[i])
                return true;
        return false;
    }
    bool add ( const char ELEMENT ) {
        if ( currentSize == size )
            return false;
        if ( isExist(ELEMENT) )
            return false;
        data[ currentSize++ ] = ELEMENT;
        return true;
    }
    Set operator + (const  char ELEMENT){
        add(ELEMENT);
        return *this;
    }
    bool isEqual (const Set &set) {
        if(set.currentSize != currentSize)
            return false;
        for ( int i = 0 ; i < set.currentSize ; i++)
            if (!(isExist(set.data[i])))
                return false;
        return true;
    }
    Set operator - (const char ELEMENT){
        int i; 
        for (i=0; i<currentSize-1; i++) 
          if (data[i] == ELEMENT) 
             break;  
       if (i < currentSize){ 
         currentSize = currentSize - 1; 
         for (int j=i; j<currentSize; j++) 
            data[j] = data[j+1]; 
        }
        return *this;
    }
    void operator * (Set &s){ 
        cout << '{';
        for (int i = 0; i < currentSize; i++) 
            for (int j = 0; j < s.currentSize; j++){
                cout << "(" << data[i] << ','  << s.data[j] << ")"; 
                if(i<currentSize-1 || j < currentSize-1)
                    cout << ',';
            }
        cout << "}\n";
    }
    Set operator + (const Set &set){
        int SIZE = currentSize + set.currentSize;
        Set newSet(SIZE);
        int i;
        for ( i = 0 ; i < currentSize ; i++)
            newSet.data [ newSet.currentSize++ ] = data [i];
        for ( i=0 ; i < set.currentSize ; i++)
            newSet.add (set.data[i]);
        return newSet;
    }
    
    Set operator - (const Set &s){
        int SIZE = currentSize;
        Set newSet(SIZE);
        for (int i = 0; i < currentSize; i++ )
            if(!(s.isExist(data[i])))
                newSet.data[newSet.currentSize++] = data[i];
        return newSet;
    }
    bool operator == (const Set set) {
        return isEqual(set);
    }
    bool operator != (const Set set) {
        return !isEqual(set);
    }
    ~Set(){
            delete []data;
    }
    friend ostream& operator << (ostream& out, Set &s);
};

ostream& operator << (ostream& out, Set &s){
    if(s.currentSize == 0) cout << "EMPTY SET";
    for( int i = 0; i < s.currentSize; i++ )
        cout << s.data[i] << ' ';
    cout << '\n';
    return out;
}

int main() {
    Set s[5];
    int noOfOp, choice, n, k, n1, n2;

    char element;
    cin >> noOfOp;
    while(noOfOp>0){
        cin >> choice;
        switch(choice){
            case 8:
                cin >> n;
                cout << s[n-1];
                break;
            case 9:
                cin >> n >> k;
                for(int i=0;i<k;i++){
                    cin >> element;
                    s[n-1] + element;
                }
                break;
            case 6:
                cin >> n1 >> n2;
                if(s[n1-1] == s[n2-1])
                    cout << "TRUE\n";
                else
                    cout << "FALSE\n";
                break;
            case 7:
                cin >> n1 >> n2;
                if(s[n1-1]!=s[n2-1]) cout << "TRUE\n";
                else cout << "FALSE\n";
                break;
            case 4:
                cin >> n >> element;
                s[n-1] + element;
                break;
            case 1:
                cin >> n1 >> n2 >> n;
                s[n-1] = s[n1-1] + s[n2-1];
                break;
            case 10:
                cin >> n1 >> n2;
                s[n1-1] = s[n2-1];
                break;
            case 2:
                cin >> n1 >> n2;
                s[n1-1]*s[n2-1];
                break;
            
        }
        noOfOp--;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}


/*
input:
15
8 2
9 2 3 A B C
8 2
9 3 3 C B A
8 3
6 2 3
7 3 2
4 3 D
4 3 E
1 2 3 1
8 1
7 1 3
7 1 2
10 4 2
2 2 4
*/
