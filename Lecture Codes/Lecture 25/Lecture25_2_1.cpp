#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Element.h"
#include "Matrix1.h"

using namespace std;


int main(){
	srand(time(0));
	Matrix1 m(4,3);
	int i,j , temp1, temp2;
	Pair<int> p; ;
	for (i=0;i<4;i++)
		for (j=0;j<3;j++){
			temp1 = rand()%99+1;
			temp2 = rand()%99+1;
			p.set(temp1, temp2);
			m.setElement(i,j,p);
		}
	cout << m << '\n';

	return 0;	
}
