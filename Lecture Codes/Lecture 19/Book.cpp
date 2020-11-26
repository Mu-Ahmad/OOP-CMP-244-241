#include <iostream>

using namespace std;

class Book{
	string title, author;
	int price;
public:
	Book(string title, string author, int price){	
		this->title = title;
		this->author = author;
		this->price = price;
	}
	friend ostream& operator << (ostream &, const Book&);
};
ostream& operator << (ostream &out, const Book &b){
	out << "Title: "<< b.title << '\n';
	out << "Author: "<< b.author << '\n';
	out << "Price: "<< b.price << '\n';
	return out;
}

