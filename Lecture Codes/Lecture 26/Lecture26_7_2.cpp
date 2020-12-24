#include <iostream> 
#include <map> 
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main() {
    map <string, int> myMap;
    myMap.insert(pair<string, int>("Ahmad",1));
    myMap.insert(pair<string, int>("Sabir",2));
    myMap.insert(pair<string, int>("Imran",3));
    myMap.insert(pair<string, int>("Bilal",4));
	
	map<string, int>::iterator it; 
	
	for ( it=myMap.begin(); it != myMap.end(); it++)
		cout << it->first << ',' << it->second << '\n';
	
	//search a value
	it = myMap.find("Sabir");
	cout << "Value against Sabir is:" << it->second << '\n';
	
	return 0;
}
