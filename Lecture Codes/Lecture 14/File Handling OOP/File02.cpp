#include <iostream>
#include <fstream>

using namespace std;

int main(){						
    //Open file in append mode means if file already exist it will not be blanked rather file pointer
	//is set at the end of file to write at the end of file
    ofstream out("test.txt", ios::app); 
    out << "\nAgain Tested\n";
    out.close();
    return 0;
}
