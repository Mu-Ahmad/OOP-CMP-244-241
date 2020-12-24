#include <iostream> 
#include <map> 
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
 
int main() {
    map<int, vector<float> > myMap;
    //take 2 vectors
    vector <float> v1, v2;
    v1.push_back(3.45);v1.push_back(2.89);v1.push_back(1.43);v1.push_back(5.35);
    v2.push_back(1.64);v2.push_back(3.42);v2.push_back(5.25);
    
	myMap.insert(pair<int, vector<float> >(1,v1));
	myMap.insert(pair<int, vector<float> >(2,v2));
	
	map<int, vector<float> >::iterator itMap;
	vector<float>::iterator itVector;
	
	for ( itMap = myMap.begin() ; itMap != myMap.end(); itMap++){
		cout << itMap->first << ':'; 
		for (itVector = itMap->second.begin();itVector != itMap->second.end(); itVector++)
			cout << *itVector << ' ';
		cout << '\n';
	}
	return 0;
}
