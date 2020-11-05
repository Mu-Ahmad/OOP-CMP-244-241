#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //Open file in append mode but if file does not exist, a new file will be created
    ofstream out("test1.txt", ios::app);
    out << "New File Created\n";
    out.close();
    return 0;
}
