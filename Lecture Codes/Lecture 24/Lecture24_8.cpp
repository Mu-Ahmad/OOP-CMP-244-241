#include <iostream>

using namespace std;

template <class T1, class T2>
class MyList{
	T1 *data1;
	T2 *data2;
	int cSize1;
	int size1;
	int cSize2;
	int size2;
	MyList& copy(MyList &list){
		size1 = list.size1;
		cSize1 = list.cSize1;
		size2 = list.size2;
		cSize2 = list.cSize2;
		data1 = new T1[size1];
		data2 = new T2[size2];
		int i	;
		for (i=0;i<cSize1;i++)
			data1[i] = list.data1[i];
		for (i=0;i<cSize2;i++)
			data2[i] = list.data2[i];
		return *this;
	}
public:
	MyList(int size1 = 10, int size2 = 10 ){
		this->size1 = size1;
		this->size2 = size2;
		cSize1 = cSize2 = 0;
		data1 = new T1[size1];
		data2 = new T2[size2];
	}
	void add1(T1 element){
		if (cSize1<size1)
			data1[cSize1++] =  element;
	}
	void add2(T2 element){
		if (cSize2<size2)
			data2[cSize2++] =  element;
	}
	MyList (const MyList &list){	copy(list);	}
	MyList& operator = (const MyList &list){	
		delete []data1;
		delete []data2;
		return copy(list);	
	}
	~MyList(){	delete []data1;	delete []data2;	}
	friend ostream& operator << (ostream &out, const MyList &list){
		int i;
		cout << "List 1: ";
		for (i=0;i<list.cSize1;i++)
			out << list.data1[i] << ' ';
		out << "\nList 2: ";
		for (i=0;i<list.cSize2;i++)
			out << list.data2[i] << ' ';
		out << '\n';
		return out;
	}	
};
int main(){
	MyList <int, char> list;
	list.add1(3);	list.add1(7);	list.add1(8);
	list.add2('H');	list.add2('G');	list.add2('T');	list.add2('Y');	list.add2('Z');
	cout << "List::\n" << list ;
	return 0;
}

