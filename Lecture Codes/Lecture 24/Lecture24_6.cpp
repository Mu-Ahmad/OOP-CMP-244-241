#include <iostream>

using namespace std;

template <class MyType>
class MyList{
	MyType *data;
	int cSize;
	int size;
	MyList& copy(MyList &list){
		size = list.size;
		cSize = list.cSize;
		data = new MyType[size];
		for (int i=0;i<cSize;i++)
			data[i] = list.data[i];
		return *this;
	}
public:
	MyList(int size = 10 ){
		this->size = size;
		cSize = 0;
		data = new MyType[size];
	}
	void add(MyType element){
		if (cSize<size)
			data[cSize++] =  element;
	}
	MyList (const MyList &list){	copy(list);	}
	MyList& operator = (const MyList &list){	
		delete []data;
		return copy(list);	
	}
	~MyList(){	delete []data;	}
	friend ostream& operator << (ostream &out, const MyList &list){
		for (int i=0;i<list.cSize;i++)
			out << list.data[i] << ' ';
		out << '\n';
		return out;
	}	
};
int main(){
	MyList <int> list1;
	list1.add(3);	list1.add(5);		list1.add(8);	list1.add(2);
	cout << "List1: " << list1 ;

	MyList <char> list2;
	list2.add('C');	list2.add('G');	list2.add('M');	list2.add('K');	list2.add('R');	
	cout << "List2: " << list2 ;

	return 0;
}

