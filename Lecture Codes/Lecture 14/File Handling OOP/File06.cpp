#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("test1.txt");
    string s;
    while (true){//Infinite loop requires some other statement to terminate the loop like break statement
        in >> s;//End of file flag is set after unsuccessful operation of reading due to end of file
        if (in.eof())   break;
        cout << s << '\n';
    }
    in.close();
    return 0;
}
