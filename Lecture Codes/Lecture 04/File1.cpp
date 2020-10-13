#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ofstream output ("Test");
	output << 1 << ' ' << 2 << '\n' << 3 << ' ' << 4 << '\n' << 5 << '\n' ;
	output.close();

	ifstream inputFile ("Test");
	int i, value;
	for (i=0 ; i<5 ; i++){
		inputFile >> value;
		cout << value <<  ' ';	
	}
	cout << '\n';
	inputFile.close();
	return 0;
}

	
