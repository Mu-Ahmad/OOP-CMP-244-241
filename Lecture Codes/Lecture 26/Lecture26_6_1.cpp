#include <iostream> 
#include <vector> 
using namespace std; 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
 
void addValuesRandomly(vector<int> &v){
	int i, size = rand() % 5 + 3;
	for (i=0;i<size;i++)
        v.push_back(rand() % 100);
} 
void readValues(vector<vector<int> > &vec){
	int i,j;
	vector<int>::iterator iter;
	for (i=0;i<vec.size();i++){
		cout << "Vector " << i+1 << ':';
		for (j=0;j<vec[i].size();j++)
			cout << vec[i][j] << ' ';
		cout << '\n';
	}
}
int main() {
    vector<int> vec[3];//Three vector objects
	vector <vector<int> > bigVector;//Vector to store vector<int> type objects
    srand(time(0));

    for (int i=0;i<3;i++){
	    addValuesRandomly(vec[i]);
	    bigVector.push_back(vec[i]);
	}
	readValues(bigVector);
	return 0;
}
