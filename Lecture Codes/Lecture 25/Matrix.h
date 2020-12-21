#ifndef MATRIX
#define MATRIX

#include "Pair.h"
#include <iostream>

template <class T>
class Matrix{
	Pair <T> **elements;
	int rows, cols;
public:
	Matrix(int rows, int cols){
		this->rows = rows;
		this->cols = cols;

		elements = new Pair<T>*[rows];

		for (int i=0;i<rows;i++)
			elements[i] = new Pair<T>[cols];
	}
	void setElement(int i, int j, Pair<T> &element){
		if (i<rows & j<cols)
			this->elements[i][j] = element; 
	}
	~Matrix(){
		for (int i=0;i<rows;i++)
			delete []elements[i];
		delete []elements;
	}
	friend ostream& operator << (ostream &out, const Matrix &matrix){
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
