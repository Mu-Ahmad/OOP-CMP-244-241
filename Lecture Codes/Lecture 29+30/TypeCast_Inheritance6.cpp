#include <iostream>
 
using namespace std;

class P{
	public:
		void f(P *p){	cout << "Function Called\n";	}
};
int main(){
	P *p1 = new P;
	const P *p2 = new P;
	//p1 -> f (p2);
	p1 -> f (const_cast<P*>(p2));
	return 0;
}
