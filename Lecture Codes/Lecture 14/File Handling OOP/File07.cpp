#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("test1.txt");
    string s;
    while (true){
        in >> s;//In case of unsuccessful reading operation, fail function will return true
        if (in.fail())  break;
        cout << s << '\n';
    }
    in.close();
    return 0;
}
