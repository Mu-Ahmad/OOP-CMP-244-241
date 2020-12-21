#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Element.h"
#include "Matrix.h"

using namespace std;


int main(){
	srand(time(0));
	Matrix <char>m (4,3);
	int i,j;
	char temp1, temp2;
	Pair<char> p; ;
	for (i=0;i<4;i++)
		for (j=0;j<3;j++){
			temp1 = rand()%26+'A';
			temp2 = rand()%26+'A';
			p.set(temp1, temp2);
			m.setElement(i,j,p);
		}
	cout << m << '\n';

	return 0;	
}
