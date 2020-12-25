#include <iostream> 
#include <vector>	 
#include <cstdlib>
#include <ctime>

using namespace std;

#define SIZE 20
#define GROUPS 4

bool isExist(vector<int> &v, const int VALUE){
	for (int i=0;i<v.size();i++)
		if (v[i] == VALUE)	return true;
	return false;
} 
void addRandomValues(vector<int> &v){
	for (int i=0, value;i<SIZE;i++){
		value = rand() % 900 + 100;//generate random values in range 100 to 1000
		if (isExist(v, value))	i--;
		else					v.push_back(value);
	}
}
void divideValuesAtRandom(vector<int> &values, vector<int> v[]){
	int i, j, choice;
	for (i=0;i<values.size();i++)
		v[rand() % GROUPS].push_back(values[i]);
	values.clear();
}
int findMinDistance(float f[], int value){
	int minDiff, diff, n=0, i=0;
	minDiff = diff = (f[0]-value) *  (f[0]-value) ;
	for (i = 1 ; i < GROUPS ; i++){
		diff = (f[i]-value) *  (f[i]-value) ;
		if (diff < minDiff){
			minDiff = diff;
			n = i;
		}
	}
	return n;
}
void divideValuesAsPerAverage(vector<int> &values, vector<int> v[], float f[]){
	int i, j, choice, n;
	for (i=0;i<values.size();i++){
		n = findMinDistance(f, values[i]);
		v[n].push_back(values[i]);
	}
	values.clear();
}

void combineValues(vector<int> &values, vector<int> v[]){
	int i, j;
	for (i=0;i<GROUPS;i++){
		for (j=0;j<v[i].size();j++)
			values.push_back(v[i][j]);
		v[i].clear();
	}
}
float showVector(vector<int> v){
	if (v.size()==0)	return 0;
	int i, s=0;
	for (i=0;i<v.size();i++){
		cout << v[i] << ' ';
		s = s + v[i];
	}
	float avg = s/(float)v.size();
	cout << ": " << avg << '\n';
	return avg;
}
int main() {
	srand(time(0));
	vector <int> values;
	addRandomValues(values);
	showVector(values);
	vector<int> v[GROUPS];
	float *avg = new float[GROUPS];
	char choice;
	int i;
	divideValuesAtRandom(values, v);
	do{
		for (i=0;i<GROUPS;i++)
			avg[i] = showVector(v[i]);
		cout << "Do you want to continue or stop [Y/N]:";
		cin >> choice;
		if (choice == 'N' || choice == 'n' )	break;
		combineValues(values, v);
		divideValuesAsPerAverage(values, v, avg);		
	}while(true);
	delete []avg;
	return 0;
}
