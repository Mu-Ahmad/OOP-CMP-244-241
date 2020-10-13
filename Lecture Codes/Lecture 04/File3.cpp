#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//Text file
	ofstream output ("StringData");
	output << "Kaleem Rehman Sabir Mughees Waheed" ;
	output.close();

	ifstream inputFile ("StringData");
	int i; string value;
	for (i=0 ; i<5 ; i++){
		inputFile >> value;
		cout << value <<  '\n';	
	}
	cout << '\n';
	inputFile.close();
	return 0;
}

	
