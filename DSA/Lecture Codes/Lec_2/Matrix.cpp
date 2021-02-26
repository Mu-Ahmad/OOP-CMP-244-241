#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define OUT_OF_BOUND_EXCEPTION -1
#define ILLEGAL_ARRAY_SIZE -2
#define OUT_OF_MEMORY -3

template <class t>
class Matrix{
	t **x;
	int rows, cols;
public:
	Matrix(int rows=3, int cols=3){
		if (rows < 1 || cols < 1)	throw ILLEGAL_ARRAY_SIZE;	
		this->rows = rows;
		this->cols = cols;
		x = new t*[rows];
		for (int i=0;i<rows;i++)
			x[i] = new t[cols];
		initRandom();
	}
	void initRandom(){
		int i,j;
		for (i=0;i<rows;i++)
			for (j=0;j<cols;j++)
				x[i][j] = rand()%9+1;
	}
	int& operator ()(const int i, const int j){
		if ( i >=0 && i < rows && j >= 0 && j < cols )
			return x[i][j];
		throw OUT_OF_BOUND_EXCEPTION; 
	}
	void show() const{
		int i,j;
		for (i=0;i<rows;i++){
			for (j=0;j<cols;j++)
				cout << x[i][j] << ' ';
			cout << '\n';
		}
	}
	~Matrix(){
		for (int i=0;i<rows;i++)
			delete []x[i];
		delete []x;
	} 
};
int main(){
	srand(time(0));
	try{
		Matrix <int> m(3,4);
		m.show();
		cout << "\nElement at 1,2:" << m(1,2) << '\n';
		cout << "\nElement at 2,0:" << m(2,0) << '\n';
		cout << "\nElement at 3,4:" << m(3,4) << '\n';
	}catch(int type){
		if (type==OUT_OF_BOUND_EXCEPTION)
			cout << "Array Index Out of Bound\n";
		else if (type == ILLEGAL_ARRAY_SIZE)
			cout << "Array size is negative\n";
	}catch (bad_alloc ba){
		cout << "Memory not available\n";
	}
	return 0;
}
