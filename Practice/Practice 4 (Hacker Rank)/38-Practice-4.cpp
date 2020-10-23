#include <iostream>

using namespace std;

class Rope{
    int feet;
    int inches;
    void normalize(){
        if (inches>=12){
            feet++;
            inches%=12;
        }
    }
    void normalize2(){
        if (inches==0){
            feet--;
            inches=11;
        }
        else if (inches >= 1 && inches <=12)
        inches--;
    }
public:
    Rope(int feet=1, int inches=0){
        if (feet==0 && inches==0)
            feet = 1;
        this->feet = feet;
        this->inches = inches;
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
    void operator>(const Rope &r){
        int size1 = (feet*12)+inches;
        int size2 = (r.feet*12)+r.inches;
        
        if(size1 > size2)
        cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    void operator==(const Rope &r){
        int size1 = (feet*12)+inches;
        int size2 = (r.feet*12)+r.inches;
        
        if(size1 == size2)
        cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    void operator>=(const Rope &r){
        int size1 = (feet*12)+inches;
        int size2 = (r.feet*12)+r.inches;
        
        if(size1 >= size2)
        cout << "TRUE\n";
        else cout << "FALSE\n";
    }
    Rope operator+(const Rope &r){
        Rope newRope;
        newRope.feet = feet + r.feet;
        newRope.inches = inches + r.inches;
        newRope.normalize();    
        return newRope;
    }
    Rope& operator+=(const Rope &r){
        feet = feet + r.feet;
        inches =inches + r.inches;
        normalize();    
        return *this;
    }

    Rope& operator++(){
        inches++;
        normalize();
        return *this;
    }
    Rope operator++(int){
        Rope newRope = *this;
        inches++;
        normalize();
        return newRope;
    }
    Rope& operator--(){
        normalize2();
        return *this;
    }
    Rope operator--(int){
        Rope newRope = *this;
        normalize2();
        return newRope;
    }
};
ostream& operator << (ostream &out,const Rope &r){
    out << "Rope is " << r.getFeet() << " feet ";
    if (r.getInches() > 0)
        out << r.getInches() << " inches ";
    out << "long\n";
    return out;
}    


int main(){
    int feet, inches;
    cin >> feet >> inches;
    Rope rope1(feet,inches);
    cout << rope1;
    cin >> feet >> inches;
    Rope rope2(feet,inches);
    cout << rope2;
    cout << rope1+rope2; 
    cout << rope1++;
    cout << ++rope1;
    cout << rope1--;
    cout << --rope1;
    cout << (rope1+=rope2);
    rope1>rope2;
    rope1>=rope2;
    rope1==rope2;
    return 0;
}
