#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//Text file
	ofstream output ("FloatData");
	output << 1.3 << ' ' << -2.65 << '\n' << 32.89 << ' ' << -4.864 << '\n' << 0.065 << '\n' ;
	output.close();

	ifstream inputFile ("FloatData");
	int i; float value;
	for (i=0 ; i<5 ; i++){
		inputFile >> value;
		cout << value <<  ' ';	
	}
	cout << '\n';
	inputFile.close();
	return 0;
}

	
