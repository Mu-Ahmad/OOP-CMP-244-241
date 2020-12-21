#ifndef MATRIX1
#define MATRIX1

#include "Pair.h"
#include <iostream>


class Matrix1{
	Pair <int> **elements;//Template class Pair is used for int data type
	int rows, cols;
public:
	Matrix1(int rows, int cols){
		this->rows = rows;
		this->cols = cols;

		elements = new Pair<int>*[rows];

		for (int i=0;i<rows;i++)
			elements[i] = new Pair<int>[cols];
	}
	void setElement(int i, int j, Pair<int> &element){
		if (i<rows & j<cols)
			this->elements[i][j] = element; 
	}
	~Matrix1(){
		for (int i=0;i<rows;i++)
			delete []elements[i];
		delete []elements;
	}
	friend ostream& operator << (ostream &out, const Matrix1 &matrix){
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
