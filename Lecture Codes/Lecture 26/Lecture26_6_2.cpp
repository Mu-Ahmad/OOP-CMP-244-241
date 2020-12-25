#include <iostream> 
#include <vector> 
#include <cstdlib>
#include <ctime>

using namespace std;
 
void addValuesRandomly(vector<int> &v){
	int i, size = rand() % 5 + 3;
	for (i=0;i<size;i++)
        v.push_back(rand() % 100);
} 
void readVectorK(vector<vector<int> > &vec, int k){
	int i,j;
	vector <int> v = vec[k];
	cout << "Values of vector " << k+1 << " are:";
	for (i=0;i<v.size();i++)
		cout << v[i]<< ' ';
	cout << '\n';
}
int main() {
    vector<int> vec[3];
	vector <vector<int> > bigVector; 
    srand(time(0));
    for (int i=0;i<3;i++){
	    addValuesRandomly(vec[i]);
	    bigVector.push_back(vec[i]);
	}
	readVectorK(bigVector,1);
	return 0;
}
