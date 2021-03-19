#include <bits/stdc++.h>

using namespace std;

bool solve(int grid[100][100], int rows, int cols, int y, int x) {
  // base Case
  if (y<0 or x<0 or y >= rows or x >= cols or (grid[y][x] == 0))
    return false;
  if (grid[y][x] == 2)
    return true;

  //Recursive Case
  bool ans = false;
  // Mark your current path
  grid[y][x] = 0;
  ans += solve(grid, rows, cols, y - 1, x) ; /*Move down*/
  ans += solve(grid, rows, cols, y + 1, x) ; /*Move up*/
  ans += solve(grid, rows, cols, y, x + 1) ; /*Move Forward*/
  ans += solve(grid, rows, cols, y, x - 1) ; /*Move backward*/
  //Track Back
  grid[y][x] = 1;
  return ans;
}

int main() {
  int rows, cols; std::cin >> rows >> cols;

  int grid[100][100];

  for (int y = 0; y < rows; y++)
    for (int x = 0; x < cols; x++)
      std::cin >> grid[y][x];

  (solve(grid, rows, cols, 0, 0))
  ? std::cout << "Path Found\n" : std::cout << "Path Not Found\n";
  return 0;
}