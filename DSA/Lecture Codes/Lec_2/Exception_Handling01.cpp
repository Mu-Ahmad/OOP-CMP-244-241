#include <iostream>

using namespace std;

int mightThrow()
{
	int i;
	cout << "Enter a number: ";
	cin >> i;
	if (cin.fail())
		throw "Some Error";
	return i;
}
void exceptionExample()
{
	int x;
	x = mightThrow();
	cout << "X = " << x << '\n';
}
int main()
{
	try
	{
		exceptionExample();
	} 
	catch (char *e)
	{
		cout << "Exception " << e << " occurred\n";
	}
	catch (...)
	{ 
		cout << "something else happened\n"; 
	}

	return 0;
}
