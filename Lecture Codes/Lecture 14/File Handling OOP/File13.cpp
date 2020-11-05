#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val, x1[10], x2[5];
    fstream inout("values.my",ios::out|ios::in|ios::app|ios::binary);
    for (int i=0; i<10 ; i++)
		x1[i] = rand() % 100;
	//To write complete array in binary file using singe statement
	inout.write ( (char*) x1, sizeof(int) * 10);

    inout.seekg(sizeof(int)*5);//Skip first 5 integers

	inout.read ( (char*) x2, sizeof(int) * 5);

	for (int j=0; j<5 ; j++)
        cout << x2[j] << ' ';
    cout << '\n' ;

    inout.close();
    return 0;
}
