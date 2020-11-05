#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("test1.txt");
	string s;
    in >> s;
    cout << s << '\n';
    in.close();
    return 0;
}
