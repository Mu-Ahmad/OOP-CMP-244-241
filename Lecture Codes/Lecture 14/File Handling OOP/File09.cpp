#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val;
    ofstream out("numbers.txt");
    for (int i=1; i<=50 ; i++)
        out << i << '\n';
    out.close();
    ifstream in("numbers.txt");
    while (true){
        in >> val;//an intelligent operation, automatically consider space (ascii value of space) and 
					// enter or \n as separator
        if ( in.eof() ) break;
        cout << val << ' ';
    }
    cout << '\n' ;
    in.close();
    return 0;
}
