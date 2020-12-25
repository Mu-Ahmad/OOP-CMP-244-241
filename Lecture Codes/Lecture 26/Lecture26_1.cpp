#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
 
int main() {
    vector<int> vec; //There is no size mentioned, however, size grows as we add elements
    int i, value;
    // Add 5 random values into the list
    cout << "Random values are: "; 
    for(i = 0; i < 5; i++) {
        value = rand() % 100;
        cout << value << ' ';
        vec.push_back(value);//push_front , push_back
    }
    cout << "\nValues from list: ";
    for(i = 0; i < 5; i++)
        cout << vec[i] << ' ';
    return 0;
}
