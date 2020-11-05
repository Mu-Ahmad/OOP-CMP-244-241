#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("test1.txt");
    string s;
    while (!in.eof()){	//repeat till reach end of file
        in >> s;		//Reading operation set the "end of file" flag value
        cout << s << '\n';
    }
    in.close();
    return 0;
}

