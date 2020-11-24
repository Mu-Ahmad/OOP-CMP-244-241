#include <iostream>
#include <fstream>

using namespace std;

class A{
	int x;
public:
	A(){	x = rand()%100 ;	} 
	friend ostream& operator << (ostream &out, const A&);
};
ostream& operator << (ostream &out, const A &a){
	out << a.x << ' ';
	return out;
}
class B{
	int count;
	A *a;
public:
	B(int count){
		this->count = count;
		a = new A[count];
	}
	void writeToFile(ostream &out){
		out.write((char*) &count, sizeof(int));
		out.write((char*) a, sizeof(int)*count);
	}
	void readFromFile(istream &in){
		in.read((char*) &count, sizeof(int));
		delete []a;
		a = new A[count];
		in.read((char*) a, sizeof(int)*count);
	}

	~B(){	delete []a;	}
	friend ostream& operator << (ostream &out, const B&);
	
};
ostream& operator << (ostream &out, const B &b){
	for (int i=0;i<b.count;i++)
		out << b.a[i];
	out << '\n';
	return out;
};

int main(){
	B b(5);
	//cout << b;
	/*ofstream out("data.bin", ios::binary);
	b.writeToFile(out);
	out.close();*/
	ifstream in ("data.bin", ios::binary);
	b.readFromFile(in);
	cout << b;
	return 0;
}


/*
*/
