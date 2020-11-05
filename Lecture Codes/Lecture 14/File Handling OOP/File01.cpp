#include <iostream>
#include <fstream>

using namespace std;

int main(){
	//If file does not exist, it will be created
	//If file already exist, then it will be blanked
    ofstream out("test.txt");//This will always a create a blank new file
    out << "ReTest\n";
    out.close();
    return 0;
}
