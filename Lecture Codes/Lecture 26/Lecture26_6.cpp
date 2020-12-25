#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
//#include <iterator>

using namespace std;
 
int main() {
	//Using Iterators
    vector<int> vec; 
    srand(time(0));
    int i, value;
    vector<int>::iterator it;
    cout << "Random values are: "; 
    for(i = 0; i < 5; i++) {
        value = rand() % 100;
        cout << value << ' ';
        vec.push_back(value);
    }
    cout << "\nValues from list: ";
    for(it=vec.begin();it!=vec.end(); it++)
        cout << *it << ' ';
	return 0;
}
