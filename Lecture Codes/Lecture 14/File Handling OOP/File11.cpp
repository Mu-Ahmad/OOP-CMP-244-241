#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int val;
	//new file will be created, if file does not exist
    fstream inout("values.txt",ios::out|ios::in|ios::app);
    for (int i=1; i<=10 ; i++)
        inout << i << ' '; //writing into value
	/*
		Moves file pointer. If single parameter is given, it is number of bytes.
		and by default the reference point is start of file means file pointer is moved from reference point
		There are three possible reference points:
			from start
			from current location
			from end
	*/
    inout.seekg(0);		//Moves file pointer to start of file
    while (true){
        inout >> val;	//reading from file
        if ( inout.eof() ) break;
        cout << val << ' ';
    }
    cout << '\n' ;
    inout.close();
    return 0;
}
