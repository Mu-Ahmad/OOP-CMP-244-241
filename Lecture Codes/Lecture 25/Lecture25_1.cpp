#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Pair.h"
#include "Matrix.h"

using namespace std;

int main(){
	srand(time(0));
	Matrix <int>m (3,4);
	int i,j, temp1, temp2;
	Pair<int> p;
	for (i=0;i<3;i++)
		for (j=0;j<4;j++){
			temp1 = rand()%9+1;
			temp2 = rand()%9+1;
			p.set(temp1, temp2);
			m.setElement(i,j,p);
		}
	cout << m << '\n';

	return 0;	
}
