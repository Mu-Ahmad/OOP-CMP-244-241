#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;


int main(){
	srand(time(0));
	Stack <int>stack (5);
	int i,  temp;
	cout << "Elements: ";
	for (i=0;i<4;i++){
		temp = rand()%1000+1;
		cout << temp << ' ';
		stack.push(temp);
	}
	cout << '\n';
	for (i=0;i<4;i++)
		cout << stack.pop() << ' ';
	cout << '\n';
	return 0;	
}
