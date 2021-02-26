#include <iostream>

using namespace std;

template <class t>
void swapElements(t &a, t &b){
	t temp = a;
	a = b;
	b = temp;
}
template <class t>
int findMinIndex(t *x, const int START, const int END){
	int minIndex = START;
	for (int i = START + 1 ; i < END ; i++)
		if (x[minIndex] > x[i])
			minIndex = i;
	return minIndex;
}
template <class a>
void selectionSort(a *x, const int SIZE){
	int minIndex;
	for (int i = 0; i < SIZE - 1 ; i++){
		minIndex = findMinIndex (x, i, SIZE);
		if (minIndex != i)
			swapElements (x[minIndex], x[i]);
	}
}
template <class b>
void printArray(b *x, const int SIZE){
	for (int i = 0; i < SIZE ; i++)
		cout << x[i] << ' ';
	cout << '\n';
}
int main(){
	int x[] = {23, 15, 18, 29, 26, 11};
	cout << "Without Sorting:";
	printArray (x, 6);
	selectionSort(x, 6);
	cout << "After Sorting:";
	printArray (x, 6);
	float y[] = {23.5, 15.8, 0.18, 2.91, 6.75, 11.121};
	cout << "\nWithout Sorting:"; 
	printArray (y, 6);
	selectionSort(y, 6);
	cout << "After Sorting:";
	printArray (y, 6);
	return 0;
}
