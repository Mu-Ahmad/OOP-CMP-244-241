#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class Ship{
	string name,year;
    protected:
    int exphours = 10;
public:
    Ship(string n,string y){
          setName(n);
          setYear(y);
}
    void setName(string n){
        this->name = n;
}
    void setYear(string y){
        this->year = y;
}

    virtual void shipArrival(){
        char choice;
        label:
        cout << "How is the weather? (S for sunny,R for rainy) >> ";cin >> choice;
        if(choice == 'S' || choice == 's' ) {cout << "Ship will reach to its destination in "<<exphours<<" hours."<<endl;}
        else if(choice == 'R' || choice == 'r')  {cout << "Ship will reach to its destination in almost "<<exphours+5<<" hours."<<endl;}
        else {cout << "Incorrect input."<<endl;goto label;}
    }
        string getName() const{
        return name;
 } 
    string getYear() const{
        return year;
 }
    virtual void print(){
        cout << "Name: "<<getName()<<endl;
        cout<< "Year: "<<getYear()<<endl<<endl;
    }
  
    
};

class CruiseShip:public Ship{
    int maxP;
    public:
    CruiseShip(string name,string year,int mP):Ship(name,year){
            setMP(mP);
    }
    void setMP(int m){
        this->maxP = m;
 }
    int getMP() const{
        return maxP;
 }
    
void shipArrival(){
        char choice;
        labelSecond:
        cout << "How is the weather? (S for sunny,R for rainy) >> ";cin >> choice;
        if(choice == 'S' || choice == 's' ) {cout << "Ship will reach to its destination in "<<exphours<<" hours."<<endl;}
        else if(choice == 'R' || choice == 'r')  {cout << "Ship will reach to its destination in almost "<<exphours+2<<" hours."<<endl;}
        else {cout << "Incorrect input."<<endl;goto labelSecond;}
    }
 
    void print(){
        cout << "Name: "<<getName()<<endl;
        cout<<"Maximum Passengers Capacity: "<<getMP()<<endl<<endl;
    }

};
class CargoShip:public Ship{
    int capacity;
    public:
    CargoShip(string name,string year,int cc):Ship(name,year){
           setCP(cc);
    }
    void setCP(int cc){
        this->capacity = cc;
 }
    int getCP() const{
        return capacity;
 }
    void print(){
        cout << "Name: "<<getName()<<endl;
        cout<<"Maximum Cargo Capacity: "<<getCP()<<" tons"<<endl<<endl;
    }
    
 void shipArrival(){
        char choice;
        labelNew:
        cout << "How is the weather? (S for sunny,R for rainy) >> ";cin >> choice;
        if(choice == 'S' || choice == 's' ) {cout << "Ship will reach to its destination in "<<exphours<<" hours."<<endl;}
        else if(choice == 'R' || choice == 'r')  {cout << "Ship will reach to its destination in almost "<<exphours+2<<" days."<<endl;}
        else {cout << "Incorrect input."<<endl;goto labelNew;}
    }
};


int main()
{
    string n="Tesla";
    string y="2020";
    Ship       ship(n,y);
    ship.print();
    CruiseShip monster(n+" X2",y+" Jan",1200);
    monster.print();
    CargoShip  hunter(n+" X3",y+" Feb",645800);
    hunter.print();
    Ship *s[3];
    s[0] = new Ship(n+" X4",y+"-4");
    s[1] = new CruiseShip(n+" X5",y+" May",48100);
    s[2] = new CargoShip(n+" X6",y+" June",4440000);
    for(int i=0;i<3;i++){
        s[i]->print();
    }
    srand(time(0));
    Ship* ShipArray[12];
    for(int i=0;i<12;i++){
        int option = rand()%3;
        switch(option){
            case 0:
                ShipArray[i]=new Ship(n+" Ship",y);
                break;
            case 1:
                ShipArray[i]=new CruiseShip(n+" Cruise Monster",y,1000);
                break;
            case 2:
                ShipArray[i]=new CargoShip(n+" Cargo Limited",y,49000);
                break;
        }
    }
    for(int i=0;i<12;i++){
        cout<<"Ship "<<i+1<<":"<<endl;
        ShipArray[i]->print();
        ShipArray[i]->shipArrival();
        cout<<endl;
    }
    
    
    return 0;
}
