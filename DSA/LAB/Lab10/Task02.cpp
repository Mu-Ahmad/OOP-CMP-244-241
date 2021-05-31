// Name: Muhammad Ahmad
// Roll: BCSF19M509

#include <iostream>

template<class T>
class Heap{
	int size;
	int capacity;
	int* data;
public:
	Heap(int capacity)
	:size(0), capacity(capacity)  {
		data = new int(capacity+1);
	}

	void add(const T ELEMENT){
		if(size==capacity) throw std::runtime_error("No Space in queue");

		// if there is space, insert new element at the end of the array
		data[++size] = ELEMENT;

		// Restore the heap property
		swim(size);

		std::cout << "Task with priority "<< ELEMENT<<" is added\n";

		return;
	}

	T remove(){
		if(size==0) throw std::runtime_error("No Element in queue");

		// Swap with last value
		std::swap(data[1], data[size]);

		// Restore the heap property
		sink(1);

		std::cout << " --> Task with priority "<< data[size] <<" is removed\n";

		// Return and Remove last element from the heap
		return data[size--];
	}

	void swim(int index){
		// Cant swim any up higher
		if(index==1) return;

		int parentIndex = index/2;

		if (data[index] > data[parentIndex]) {
			// skip up and keep swimming
			std::swap(data[index], data[parentIndex]);
			swim(parentIndex);
		}
		return;
	} 

	void sink(int index){
		// Can't sink any lower 
		if(isLeaf(index)) return;

		int minChildI = minChildIndex(index);

		if (data[index] < data[minChildI]) {
			// skip down and keep sinking
			std::swap(data[index], data[minChildI]);
			sink(minChildI);
		}
		return;
	}

	bool isLeaf(int index) {
		// A leaf node has no children, so it is a leaf
		// if the left child (index*2) is larger than the size
		// of the heap
		return index * 2 > size;
	}

	int minChildIndex(int index) {
		int left = index * 2;
		int right = left + 1;


		// If left child only
		if (right > size) return left;

		if (data[left] < data[right]) return left;

		return right;
	}
};

int main(){
	Heap<int> tasks(10);
	tasks.add(25);
	tasks.add(36);
	tasks.add(28);
	tasks.add(45);
	tasks.remove();
	tasks.add(29);
	tasks.add(42);
	tasks.remove();
	return 0;
}