#include <iostream>

using namespace std;

class Book{
	string title, author;
	int price;
public:
	void set(string t, string a, int p){
		title = t;
		author = a;
		price = p;
	}
	void showBook() const{   	//This function is not allowed to change value of data member
		cout << title << '\n' ;
		cout << author << '\n' ;
		cout << price << '\n' ;
	}
};

void f1() const{
	cout << "Test Function\n";
}

int main(){
	Book book;
	book.set("OOP","Tony Gaddis", 800);
	book.showBook();
	return 0;
}


