#include <iostream> 
#include <map>	 
#include <cstdlib>
#include <ctime>

using namespace std;
 
#define SIZE 20
#define SEN -1

void generateRandomScores(int *x){
	for (int i=0;i<SIZE;i++)
		x[i] = rand() % 9 + 1;
}
void showArray(int *x){
	for (int i=0;i<SIZE;i++)
		cout << x[i] << ' ';
	cout << '\n';
}
void showFrequency(int *x){
	int f = 0, i, j;
	map <int, int> m;
	for (i=0;i<SIZE;i++){
		if (m.find(x[i])!=m.end())		continue;
		else							f=1;
		for (j=i+1;j<SIZE;j++)
			if (x[i] == x[j])
				f++;
		m.insert(pair<int, int>(x[i], f));//(key,value) pair
		//cout << x[i] << ':' << f << '\n';
	}
	map <int, int> :: iterator it;
	for (it=m.begin();it != m.end()	;	it++ )
		cout << it->first << ':' << it->second << '\n';
}
int main() {
	srand(time(0));
	int *x = new int[SIZE];
	generateRandomScores(x);
	showArray(x);
	showFrequency(x);
	delete []x;
	return 0;
}
