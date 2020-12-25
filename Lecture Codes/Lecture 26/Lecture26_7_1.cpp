#include <iostream> 
#include <map> 
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main() {
    map<int, string> myMap;
    myMap.insert(pair<int, string>(1,"Ahmad"));
    myMap.insert(pair<int, string>(2,"Sabir"));
    myMap.insert(pair<int, string>(3,"Imran"));
    myMap.insert(pair<int, string>(4,"Bilal"));
	
	map<int, string>::iterator it = myMap.begin();
	
	for ( ; it != myMap.end(); it++)
		cout << it->first << ',' << it->second << '\n';
	
	//search a value
	it = myMap.find(3);
	cout << "Value against 3 is:" << it->second << '\n';
	
	return 0;
}
