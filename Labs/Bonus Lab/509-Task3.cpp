#include <iostream>
#include <ctime>
#include <iomanip>

class Matrix {
	int M; //rows,
	int N; // cols
	int** data;
	void copyMatrix(const Matrix& other) { //Allocate memory and copy
		M = other.M;
		N = other.N;
		data = new int*[M];
		for (int i = 0; i < M; i++) {
			data[i] = new int[N];
			for (int j = 0; j < N; j++)
				data[i][j] = other.data[i][j];
		}
	}
public:
	Matrix(const int& M, const int& N)
		: M(M), N(N) {
		data = new int*[M];
		for (int i = 0; i < M; i++)
			data[i] = new int[N];
	}

	Matrix(const int& M, const int& N, const int num)
		: M(M), N(N) {
		data = new int*[M];
		for (int i = 0; i < M; i++) {
			data[i] = new int[N];
			for (int j = 0; j < N; j++)
				data[i][j] = num;
		}

	}
	Matrix(const Matrix& other)	{
		copyMatrix(other);
	}

	Matrix& operator=(const Matrix& other) {
		this->~Matrix(); // Free Current Memory
		copyMatrix(other);
		return *this;
	}

	Matrix operator+(const Matrix& other) {
		Matrix newMatrix(*this); //Will copy current matrix values in new
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				newMatrix.data[i][j] += other.data[i][j];
		return newMatrix;
	}

	Matrix operator-(const Matrix& other) {
		Matrix newMatrix(*this); //Will copy current matrix values in new
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				newMatrix.data[i][j] -= other.data[i][j];
		return newMatrix;
	}

	Matrix& operator+=(const Matrix& other) {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				data[i][j] += other.data[i][j];
		return *this;
	}

	Matrix operator*(const Matrix& other) {
		Matrix newMatrix(this->M, other.N, 0); //Init to 0

		for (int i = 0; i < newMatrix.M; i++)
			for (int j = 0; j < newMatrix.N; j++) {
				for (int k = 0; k < this->N; k++)
					newMatrix.data[i][j] += data[i][k] * other.data[k][j];
			}
		return newMatrix;
	}

	Matrix& operator*=(const Matrix& other) {
		if (M == other.M and N == other.N)
			*this = (*this) * other;
		return *this;
	}

	void Randomize() {
		for (int i = 0; i < M; i++)
			for (int j = 0; j < N; j++)
				data[i][j] = rand() % 10;
	}

	~Matrix() {
		for (int i = 0; i < M; i++)
			delete[] data[i];
		delete[] data;
	}

	friend std::ostream& operator<<(std::ostream& out, const Matrix& other) {
		for (int i = 0; i < other.M; i++) {
			out << "|";
			for (int j = 0; j < other.N; j++)
				out << std::setw(3) << other.data[i][j] << ' ';
			out << "|\n";
		}
		return out;
	}
};


int main() {
	srand(time(0));
	Matrix a2x2(2, 2);
	a2x2.Randomize();
	std::cout << "Matrix 1:\n" << a2x2 << '\n';
	Matrix b2x2(2, 2);
	b2x2.Randomize();
	std::cout << "Matrix 2:\n" << b2x2 << '\n';
	std::cout << "Matrix 1 + Matrix 2:\n" << a2x2 + b2x2 << '\n';
	std::cout << "Matrix 1 - Matrix 2:\n" << a2x2 - b2x2 << '\n';
	std::cout << "Matrix 1 * Matrix 2: \n" << a2x2 * b2x2 << '\n';

	std::cout << "===============================For 3x3 matrix===========================\n";
	Matrix a3x3(3, 3);
	a3x3.Randomize();
	std::cout << "Matrix 1:\n" << a3x3 << '\n';
	Matrix b3x3(3, 3);
	b3x3.Randomize();
	std::cout << "Matrix 2:\n" << b3x3 << '\n';
	std::cout << "Matrix 1 + Matrix 2:\n" << a3x3 + b3x3 << '\n';
	std::cout << "Matrix 1 - Matrix 2:\n" << a3x3 - b3x3 << '\n';
	std::cout << "Matrix 1 * Matrix 2: \n" << a3x3 * b3x3 << '\n';
	return 0;
}