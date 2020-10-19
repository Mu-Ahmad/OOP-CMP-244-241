#include <iostream>
#include <utility>
#include <climits>
using namespace std;

//returning a pair data structure with the ending point of the optimal sub matrix
//You can use an array with two elements for the same purpose but make sure its heap allocted.
pair<int, int> solve(int **A, int B, int n) {
	int row = n, col = n, maxSum = INT_MIN;
	pair<int, int> point;

	//This is a naive approach to the solution, we calculate sum for all possible submatrices of the specified size i.e kxk
	//and maintains the coordinates of the submatrix with the best(max) sum.
	for (int i = 0; i <= row; i++)
		for (int j = 0; j <= col; j++) {
			if (i + B <= row && j + B <= col) {
				int sum = 0;
				for (int k = i; k < i + B; k++)
					for (int l = j; l < j + B; l++)
						sum += A[k][l];
				if (sum > maxSum) {
					maxSum = sum;
					point = make_pair(i + B, j + B);
				}
			}
		}
	return point;
}

int main() {
	int n, k; cin >> n >> k; // Input the size of a square matrix and sub-square-matrix

	// It is not necessary to allocate the memory on heap but hey, we do it anyways
	int **matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int [n];

	//Reading the data
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> matrix[i][j];

	//Calls the sub-routine to get the coordinates of the max sum submatrix of the matrix "matrix"
	pair<int, int> point = solve(matrix, k, n);

	cout << "Printing Solution-----------------\n";
	cout << "It starts at row : " << point.first - k + 1 << " and coloumn: " << point.second - k + 1 << '\n';
	//Its pretty much clear what this bit do.
	for (int i = point.first - k; i < point.first; i++) {
		for (int j = point.second - k; j < point.second; j++)
			cout << matrix[i][j] << ' ';
		cout << "\n";
	}
	return 0;
}
