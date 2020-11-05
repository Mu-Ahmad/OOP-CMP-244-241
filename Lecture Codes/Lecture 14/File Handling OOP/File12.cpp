#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val, x1[10], x2[10];
    fstream inout("values.my", ios::out | ios::in | ios::app | ios::binary);
	//Storing random two digit values into x1
    for (int i=0; i<10 ; i++)
		x1[i] = rand() % 100;
	//To write complete array in binary file using singe statement
	// write / read function has first parameter memory location
	// write / read function has second parameter is no of bytes
	inout.write ( (char*) x1 , sizeof(int) * 10);

    inout.seekg(0);

	//Reading from file into array x2
	inout.read ( (char*) x2, sizeof(int) * 10);

	for (int j=0; j<10 ; j++)
        cout << x2[j] << ' ';
    cout << '\n' ;

    inout.close();
    return 0;
}
