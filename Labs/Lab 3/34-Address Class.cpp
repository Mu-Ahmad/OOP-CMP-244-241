#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Address{

public: 
    Address(int hous, char flor, char bloc) {
       if (hous < 1 || hous > 8) {
           houseNo = 1;
       }
       else {
          setHouseNo(hous);   
        }
        if (flor < 'a' || flor > 'd') {
            floor = 'a';
        }
        else {
            setFloor(flor);
        }
        if (bloc < 'A' || bloc > 'J') {
            block = 'A';
        }
        else {
            setBlock(bloc);
        }
    }
    void setHouseNo(int hous) {
        houseNo = hous;
    }
    void setFloor(int fl) {
        floor = fl;
    }
    void setBlock(int bl) {
        block = bl;
    }
    int getHouseNo() const{
        return houseNo;
    }
    char getFloor() const {
        return floor;
    }
    char getBlock() const {
        return block;
    } 
    bool isSameBlock(Address a) {
        if (a.block == block) {
            return true;
        }
        else {
            return false;
        }
    }
    bool hasUpperFloor(Address b) {
        if (floor > b.floor) {
            return true;
        }
        else {
            return false;
    }
    }
    void show() const {
        cout << "House No:" << houseNo << '\n';
        cout << "Floor:" << floor << '\n';
        cout << "Block:" << block << '\n';
        cout << "------------\n";
    }
private:
    int houseNo;
    char floor;
    char block;
};

int main(){

int h; char f, b;

cin>>h>>f>>b;

Address a1(h, f, b);

cin>>h>>f>>b;

Address a2(h, f, b);

a1.show();

a2.show();

if (a1.isSameBlock(a2))

    cout<<"has same block\n";

else

    cout<<"has different block\n";

cin>>f;

a1.setFloor(f);

if (a1.hasUpperFloor(a2))

    cout<<"has upper floor\n";

else

    cout<<"has same or lower floor\n";

a2.setFloor('c');

cout<<"A2 has floor:"<<a2.getFloor()<<'\n';

cout<<"Block:"<<a2.getBlock()<<'\n';

cout<<"House no:"<<a1.getHouseNo()<<'\n';

return 0;
}

