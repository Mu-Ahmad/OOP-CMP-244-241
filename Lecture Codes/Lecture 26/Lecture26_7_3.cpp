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
	
	cout << '\n';
	
	//replace a value
	myMap.insert(pair<int, string>(2,"Shabbir"));
	myMap.insert(pair<int, string>(5,"Mansoor"));
	myMap.insert(pair<int, string>(6,"Imran"));

	for ( it =  myMap.begin(); it != myMap.end(); it++)
		cout << it->first << ',' << it->second << '\n';
	
	return 0;
}
