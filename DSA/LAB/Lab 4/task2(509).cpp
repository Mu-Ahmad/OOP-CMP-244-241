#include <bits/stdc++.h>

#define BOARD_SIZE 10
//Global Variable to hold size of a distinct white block when found
int ans;

void dfsSearch(char board[BOARD_SIZE][BOARD_SIZE], int y, int x) {
	// Base Case
	if (y<0 or y >= BOARD_SIZE or x<0 or x >= BOARD_SIZE or board[y][x] == 'b')
		return;
	// Recursive Case
	board[y][x] = 'b';
	ans++;
	// Continue Search
	dfsSearch(board, y + 1, x);  /*Down*/
	dfsSearch(board, y - 1, x);  /*Up*/
	dfsSearch(board, y, x + 1);  /*Right*/
	dfsSearch(board, y, x - 1);  /*left*/

	return ;
}

int main() {
	char board[BOARD_SIZE][BOARD_SIZE];

	for (int y = 0; y < BOARD_SIZE; y++)
		for (int x = 0; x < BOARD_SIZE; x++)
			std::cin >> board[y][x];

	int count = 0;
	for (int y = 0; y < BOARD_SIZE; y++)
		for (int x = 0; x < BOARD_SIZE; x++)
			if (board[y][x] == 'w') {
				count++;
				// setting the global variable to zero; It records the length of recursion tree i.e size of contiguous white block
				ans = 0;
				dfsSearch(board, y, x); // populates ans and mark all contiguous white to black so they are not counted again
				std::cout << ans << ' ';
			}
	std::cout << "\nNumber of white areas:" << count << '\n';
	return 0;
}

/*
Input0: (Actual Example)
b b b b b b b b b b
b w b b w w w w w b
b b b b w b b b b b
b b b b w w w b w w
b b w b b b w b b b
b b w w b w w b b b
b b b b w w b w w w
b b w w w b w w w w
b b w w w b b w w w
b b b b b b b b b b
Output0:
1 20 2 3 10
Number of white areas:5
Input1: (Written Example)
b b b b b b b b b b
b w b b w w w w w b
b b b b w b b b b b
b b b b w w w b w w
b b w b b b w b b b
b b w w b w w b b b
b b b b w w b w w w
b b w w w b w w w w
b b w w w b b w w w
b b b b b b b b b b
Output1:
1 20 2 3 10
Number of white areas:5
-----------------------
Input2: 8x8 (Diagram 1)
b b w w w w w w
b b w w b w w b
w w b b w b b w
w w b b w b b w
w b w w b w w b
w w b b w b b w
w w b b w b b w
w b w w b w w b
Output2:
10 10 2 2 2 2 2 2 2 2
Number of white areas:10
-----------------------
Input3: 8x8 (Diagram 2)
w b b w w b w w
b b b b w b w w
w w w b b w w w
w b w b w w b b
w b w w w b w b
w b b b b w w w
w b w b b w w w
w b w b b w w w
Output3:
1 3 21 10 2
Number of white areas:5
Input4:  (Edge Case)
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
w w w w w w w w w w
Output4:
100
Number of white areas:1
*/