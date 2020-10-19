#include <iostream>
#include <climits>

//This is the recursive solution to the problem, we can improve the running time by adding memoization
int coinChangeRecursive(int * coins, int n, int change) {
	//Base Case
	if (change == 0)
		return 0;

	//Recursive case
	int globalMin = INT_MAX;
	for (int i = 0; i < n; i++)
		if (change >= coins[i])
			globalMin = std::min(globalMin, coinChangeRecursive(coins, n, change - coins[i]));
}


//This is bottom up DP solution, its running time will be similar to recursion with memoization
int coinChangeIterative(int * coins, int n, int change) {
	int dp[change + 1] = {0};

	for (int i = 1; i <= change; i++) {
		dp[i] = INT_MAX;
		for (int j = 0; j < n; j++)
			if (change >= coins[j])
				dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
	}
	return dp[change];
}

int main() {
	int n; std::cin >> n;
	int coins[n];
	for (int i = 0; i < n; i++) std::cin >> coins[i];
	int change; std::cin >> change;
	std::cout << coinChangeRecursive(coins, n, change) << '\n';
	std::cout << coinChangeIterative(coins, n, change) << '\n';
	return 0;
}


/*
Input: n = 3, coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
*/

/*
Input: n = 3, coins = [1, 7, 10], amount = 15
Output: 3
Explanation: 11 = 7 + 7 + 1
*/

/*
Input: n = 1, coins = [1], amount = 2
Output: 2
*/
