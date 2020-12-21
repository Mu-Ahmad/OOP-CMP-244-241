#ifndef MATRIX2
#define MATRIX2

#include "Pair.h"
#include <iostream>

class Matrix2{
	Pair <char> **elements;
	int rows, cols;
public:
	Matrix2(int rows, int cols){
		this->rows = rows;
		this->cols = cols;

		elements = new Pair<char>*[rows];

		for (int i=0;i<rows;i++)
			elements[i] = new Pair<char>[cols];
	}
	void setElement(int i, int j, Pair<char> &element){
		if (i<rows & j<cols)
			this->elements[i][j] = element; 
	}
	~Matrix2(){
		for (int i=0;i<rows;i++)
			delete []elements[i];
		delete []elements;
	}
	friend ostream& operator << (ostream &out, const Matrix2 &matrix){
		int i, j;
		for (i=0;i<matrix.rows;i++){
			for (j=0;j<matrix.cols;j++)
				out << matrix.elements[i][j]<< ' ';
			out << '\n';
		}
		return out;
	}
};
#endif
