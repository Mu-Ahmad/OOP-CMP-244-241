#include <iostream>
#include <vector>

// Remember to have fun

using namespace std;

bool groupSome(int curr, vector<int> arr, int targetSum, int runningSum) {
	// base case
	if (runningSum == targetSum)
		return true;

	if (curr == arr.size())
		return false;

	// recursive
	return groupSome(curr + 1, arr, targetSum, runningSum + arr[curr]) +
	       groupSome(curr + 1, arr, targetSum, runningSum);
}


bool groupSome6(int curr, vector<int> arr, int targetSum, int runningSum) {
	// base case
	if (runningSum == targetSum)
		return true;

	if (curr == arr.size())
		return false;

	// recursive
	return groupSome6(curr + 1, arr, targetSum, runningSum + arr[curr]) +
	       ((arr[curr] % 6) ? groupSome6(curr + 1, arr, targetSum, runningSum) : 0);
}

bool splitArray(int curr, vector<int> arr, int group1, int group2) {
	// Base Case
	if (curr == arr.size())	return group1 == group2;

	// Recursive Case
	return splitArray(curr + 1, arr, group1 + arr[curr], group2) +
	       splitArray(curr + 1, arr, group1 , group2 + arr[curr]);
}

bool splitArray53(int curr, vector<int> arr, int group1, int group2) {
	// Base Case
	if (curr == arr.size())	return group1 == group2;

	// Recursive Case
	return ((arr[curr] % 5) ? splitArray53(curr + 1, arr, group1 + arr[curr], group2) : 0) +
	       (((arr[curr] % 3 == 0) and (arr[curr] % 5)) ? 0 : splitArray53(curr + 1, arr, group1 , group2 + arr[curr]));
}

int main() {
	vector<int> arr = {5, 3, 8};
	cout << splitArray(0, arr, 0, 0) << '\n';
	cout << splitArray53(0, arr, 0, 0) << '\n';
	return 0;
}


