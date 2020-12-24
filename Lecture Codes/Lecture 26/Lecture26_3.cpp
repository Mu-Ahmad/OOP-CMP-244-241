#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
 
int main() {
    vector<int> vec; 
    srand(time(0));
    int i, value;
    cout << "Vector Size:"	<< vec.size() << '\n';
    cout << "Random values are: "; 
    for(i = 0; i < 5; i++) {
        value = rand() % 100;
        cout << value << ' ';
        vec.push_back(value);
    }
    cout << "\nValues from list: ";
    for(i = 0; i < 5; i++)
        cout << vec[i] << ' ';
    cout << "\nVector Size:"	<< vec.size() << '\n';

    cout << "Removing third value \n";

	vec.erase(vec.begin()+2); //Removing third value from vector

    cout << "\nNew Vector Size:"	<< vec.size() << '\n';

    cout << "Remaing values:";
    for(i = 0; i < 4; i++)
        cout << vec[i] << ' ';
	return 0;
}
