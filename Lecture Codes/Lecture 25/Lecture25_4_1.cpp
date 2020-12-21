#include <iostream>
#include <cstdlib>
#include <ctime>
#include "MyStack1.h"

using namespace std;


int main(){
	srand(time(0));
	MyStack1<int> stack (5);
	int i;
	int temp;
	cout << "Elements Push In Order: ";
	for (i=0;i<4;i++){
		temp = rand()%99+1;
		cout << temp << ' ';
		stack.push(temp);
	}
	cout << '\n';
	cout << "Stack Top: " << stack.seeTop() << '\n';
	cout << "Elements Pop Out Order: ";
	for (i=0;i<4;i++)
		cout << stack.pop() << ' ';
	cout << '\n';
	return 0;	
}
