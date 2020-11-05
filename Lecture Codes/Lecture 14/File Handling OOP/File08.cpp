#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val;
    ofstream out("numbers.txt");
    for (int i=1; i<=50 ; i++)
        out << i << ' ';
    out << '\n';
    out.close();
    ifstream in("numbers.txt");
    while (true){
        in >> val;
        if (in.fail())  break;
        cout << val << ' ';
    }
    cout << '\n' ;
    in.close();
    return 0;
}
