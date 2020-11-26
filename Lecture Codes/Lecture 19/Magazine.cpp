#include <iostream>
#include "Book.cpp"

using namespace std;

class Magazine:public Book{
	string issue;
public:
	Magazine(string title, string author, int price, string issue):Book(title, author, price){	
		this->issue = issue;
	}
	friend ostream& operator << (ostream &, const Magazine&);
};
ostream& operator << (ostream &out, const Magazine &m){
	out << (Book)m;
	out << "Issue: "<< m.issue << '\n';
	return out;
}

