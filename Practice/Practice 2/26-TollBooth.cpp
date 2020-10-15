#include<iostream>
using namespace std;

class TollBooth
{
    unsigned int totalCars;
    double totalMoney;
public:
    TollBooth()
    {
        totalCars = 0;
        totalMoney = 0;       
    }
    void payingCar()
    {
        totalCars++;
        totalMoney += 0.50;
    }
    void nopayingCar()
    {
        totalCars++;
    }
    void display()
    {
        cout << "Total Cars passed: " << totalCars << endl;
        cout << "Total Money Collected: " << totalMoney << endl;
    }
};

int main()
{
    TollBooth t;
    while(true)
    {
        cout << "/***************************/\n"
             << "         Options             \n"
             << "/***************************/" << endl;
        cout << "    Press 1 for paying car   \n"
             << "   Press 2 for nopaying car  \n"
             << "    Press 0 to terminate     " << endl;
        int n;
        cin >> n;     
        switch (n)
        {
        case(1):
            t.payingCar();
            break;
        case(2):
            t.nopayingCar();
            break;
        case(0):
            t.display();
            return 0;
        default:
            cout << "Invalid input!!!!\n";
            break;
        }         
    }
}