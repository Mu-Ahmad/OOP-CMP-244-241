#include <iostream>
#include <cmath>
#include <numeric>

using namespace std;

// O(n) Approach using running sum technique
int solve(int* runningSum, int n, int curr, int ans, int globalMin) {
  // Base Case
  if (curr == n)  return ans;

  // Recursive Case
  int diff = abs(runningSum[n] - 2 * runningSum[curr]);
  if (diff < globalMin) {
    ans = curr;
    globalMin = diff;
  }
  return solve(runningSum, n, curr + 1, ans, globalMin);
}

int main() {
  int n; cin >> n;
  int arr[n];
  int runningSum[n + 1] = {0} ;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    runningSum[i + 1] = arr[i] + runningSum[i];
  }

  // O(n^2) approach
  int ans = 0; int globalMin = 100000;
  for (int i = 0; i < n; i++) { // O(n)
    int group1 = accumulate(arr, arr + i, 0);   // O(n)
    int group2 = accumulate(arr + i, arr + n, 0); // O(n)
    int diff = abs(group1 - group2);
    if (diff < globalMin) {
      ans = i;
      globalMin = diff;
    }
  }

  cout << ans << '\n';

  // O(n) approach
  cout << solve(runningSum, n, 1, 0, 10000) << '\n';

  return 0;
}

/*
“If we were meant to stay in one place, we'd have roots instead of feet.”

Rachel Wolchin
*/