#include <iostream>

using namespace std;

template <class Type>
int findMinIndex(Type *a, int start, const int SIZE){
	int minIndex = start;
	for (int i=start+1;i<SIZE;i++)
		if (a[i]<a[minIndex])
			minIndex = i;
	return minIndex;
}
template <class T>
void swap1(T &a, T &b){
	T temp = a;
	a = b;
	b = temp;
}
class List{
	int *data;
	int size;
public:
	List(int size=10){
		this->size = size;
		data = new int[size];
		for (int i=0;i<size;i++)
			data[i] = rand()% 100;
	}
	void sort(){
		int minIndex;
		for (int i=0;i<size-1;i++){
			minIndex = findMinIndex(data, i, size);
			if (minIndex!=i)
				swap1(data[i], data[minIndex]);
		}
	}
	friend ostream& operator << (ostream &out, const List &list){
		for (int i=0;i<list.size;i++)
			out << list.data[i] << ' ';
		out << '\n';
		return out;
	}
};
int main(){
	List list;
	cout << list;
	list.sort();
	cout << list;
	return 0;
}
