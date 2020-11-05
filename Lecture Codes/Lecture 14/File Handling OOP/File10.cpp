#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val;
	//Open previous file, no file created if file does not exist
    fstream inout("values.txt",ios::out | ios::in);
    for (int i=1; i<=10 ; i++)
        inout << i << ' ';
    inout.seekg(0);//Moves 0 bytes from start of file
    while (true){
        inout >> val;
        if ( inout.eof() ) break;
        cout << val << ' ';
    }
    cout << '\n' ;
	inout.close();
    return 0;
}
