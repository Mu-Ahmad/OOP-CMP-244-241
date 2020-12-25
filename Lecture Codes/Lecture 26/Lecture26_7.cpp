#include <iostream> 
#include <map> 
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main() {
    map <int, string> myMap;//Map is key, value pair
    myMap.insert(pair<int, string>(1,"Ahmad"));
    myMap.insert(pair<int, string>(2,"Sabir"));
    myMap.insert(pair<int, string>(3,"Imran"));
    myMap.insert(pair<int, string>(4,"Bilal"));
	
	map<int, string>::iterator it;
	
	for ( it = myMap.begin(); it != myMap.end(); it++)
		cout << it->first << ',' << it->second << '\n';
	return 0;
}
