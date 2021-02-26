#include <iostream>
 
using namespace std;

class P{
	public:
		virtual void f(){	cout << "Function of P\n";}
};
class P1:public P{
	public:
		void f(){	cout << "Function of P1\n";}
};
class P2:public P{
	public:
		void f(){	cout << "Function of P2\n";}
};
class P3:public P{
	public:
		void f(){	cout << "Function of P3\n";}
		virtual void f3(){	cout << "Function only in P3\n";}
};
int main(){
	P *p = new P1;
	p->f();
	P3 *p3 = dynamic_cast<P3*>(p);
	if (p3==0)		cout << "Cast is unsuccessful\n";
	else 			p3->f3();
	return 0;
}
