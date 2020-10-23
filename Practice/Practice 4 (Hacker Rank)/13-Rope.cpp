#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Rope{
    int feet;
    int inches;
    void normalize(){
        if (inches>=12){
            feet += inches/12;
            inches%=12;
        }
    }
    public:
    Rope(int feet=1, int inches=0){
        if (feet==0 && inches==0)
            feet = 1;
        this->feet = feet;
        this->inches = inches;
    }
    // Copy constructor
    Rope(Rope const &rope){
        this->feet = rope.feet;
        this->inches = rope.inches;
    }

    void setFeet(int feet){
        this->feet = feet;
    }
    void setInches(int inches){
        this->inches = inches;
    }
    int getFeet() const{
        return feet;
    }
    int getInches() const{
        return inches;
    }

    // operator overloading

    Rope operator += (Rope& rope){
        this->feet += rope.feet;
        this->inches += rope.inches;
        normalize();
        return *this;
    }
    bool operator > (Rope& rope){
        if(this->feet > rope.feet ) return true;
        else if(this->inches > rope.inches) return true;
        else return false;
    }
    bool operator >= (Rope& rope){
        if(this->feet >= rope.feet ) return true;
        else if(this->inches >= rope.inches) return true;
        else return false;
    }
    bool operator == (Rope& rope){
        return (this->feet == rope.feet &&  this->inches == rope.inches);
    }
    Rope operator + (const Rope &r){
        Rope newRope;
        newRope.feet = feet + r.feet;
        newRope.inches = inches + r.inches;
        newRope.normalize();
        return newRope;
    }
    Rope operator ++ (){
        inches++;
        normalize();
        return *this;
    }
    Rope operator ++ (int){
        Rope newRope = *this;
        inches++;
        normalize();
        return newRope;
    }
    Rope operator -- (){
        inches--;
        normalize();
        return *this;

    }
    Rope operator -- (int){
        Rope newRope = *this;
        inches--;
        normalize();
        return newRope;
    }
    friend ostream& operator << (ostream &out, Rope &r);
};
ostream& operator << (ostream &out, Rope &r){
    out << "Rope is " << r.getFeet() << " feet ";
    if (r.getInches() > 0)
        out << r.getInches() << " inches ";
    out << "long\n";
    return out;
}
int main() {
    Rope rope[2]; int f, i;
    for(int no=0;no<2;no++){
        cin >> f >> i;
        rope[no].setFeet(f);
        rope[no].setInches(i);
        cout << rope[no];
    }
    Rope testRope, addedRopes(rope[0]+rope[1]);
    cout << addedRopes;
    testRope = rope[0]++;
    cout << testRope;
    testRope = ++rope[0];
    cout << testRope;
    testRope = rope[0]--;
    cout <<testRope;
    testRope = --rope[0];
    cout << testRope;
    rope[0]+=rope[1];
    cout << rope[0];
    if(rope[0] > rope[1])
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    if(rope[0] >= rope[1])
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    if(rope[0] == rope[1])
        cout << "TRUE\n";
    else
        cout << "FALSE\n";
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
