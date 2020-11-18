#include <iostream>
#include "List.h"

using namespace std;

//Name of the class followed by double colon (scope resolution operator)
List::List(int s): SIZE(s){
	data = new int[SIZE];
	setValuesRandomly();
}
//Function return type will come first, followed by class name, followed by scope resuolution operator,
//followed by function name
void List::setValuesRandomly(){
	for (int i=0;i<SIZE;i++)
		data[i] = rand() % 100 ;
}
void List::show() const{
	for (int i=0;i<SIZE;i++)
		cout << data[i] << ' ';
	cout << '\n';
}
