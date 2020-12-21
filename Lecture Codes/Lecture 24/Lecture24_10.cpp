#include <iostream>

using namespace std;

template <class T>
void insertionSort(T *x, const int SIZE){
	T temp;
	int i, j;
	for (i=1;i<SIZE;i++){
		temp = x[i];
		for (j=i-1;j>=0 && x[j]>temp;j--)
			x[j+1] = x[j];
		x[j+1] = temp;
	}
};
template <class T>
void showArray(T *x, const int SIZE){
	for (int i=0;i<SIZE;i++)
		cout << x[i] << ' ';
	cout << '\n';
}
int main(){
	int x[]={3,8,1,7,9,2,4,6,5};
	showArray(x, 9);
	insertionSort(x, 9);
	showArray(x, 9);

	char c[]={'C','G','A','H','F'};
	showArray(c, 5);
	insertionSort(c, 5);
	showArray(c, 5);

	return 0;
}

