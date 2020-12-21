#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"

using namespace std;


int main(){
	srand(time(0));
	Stack <char>stack (5);
	int i;
	char temp;
	cout << "Elements: ";
	for (i=0;i<4;i++){
		temp = rand()%26+'A';
		cout << temp << ' ';
		stack.push(temp);
	}
	cout << '\n';
	for (i=0;i<4;i++)
		cout << stack.pop() << ' ';
	cout << '\n';
	return 0;	
}
