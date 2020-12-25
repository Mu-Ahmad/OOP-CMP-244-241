#include <iostream> 
#include <vector>	 
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

//Frequency result is un sorted
//Either we are modifying existing array
//or we have to create copy of existing array for manipulation
void showFrequency(int *x){
	int f = 0, i, j;
	for (i=0;i<SIZE;i++){
		if (x[i] != SEN)	f=1;
		else 				continue;//skip this iteration and go to top of the loop
		for (j=i+1;j<SIZE;j++)
			if (x[j]!=SEN && x[i] == x[j]){
				f++;
				x[j] = SEN;
			}
		cout << x[i] << ':' << f << '\n';
	}
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
