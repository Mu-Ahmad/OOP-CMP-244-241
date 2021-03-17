#include <iostream>
#include <string.h>

// =====================Problem-1===================
int putCommas(std::string& str, int curr) {
	// Base Case
	if (curr < 4) {
		str.insert(curr, ",");
		return 1;
	}

	// Recursive Case
	int depth = putCommas(str, curr - 3);
	str.insert(curr + depth, ",");
	return depth + 1;
}

std::string putCommas(const long long num) {
	std::string str = std::to_string(num);
	putCommas(str, str.length() - 3);
	return str;
}

// =====================Problem-2===================
void syracuseSequence(const int n) {
	// Base Case
	if (n == 1) {
		std::cout << n << '\n';
		return;
	}

	// Recursive Case
	std::cout << n << ' ';
	return (n % 2) ? syracuseSequence(3 * n + 1) : syracuseSequence(n / 2);
}

// =====================Problem-3===================
long long multiply(const int x, const int y) {
	// base Case
	if (y == 1)	return x;

	// recursive case
	return x + multiply(x, y - 1);
}

// =====================Problem-4===================
long long bCoefficient(const int n, const int k) {
	// Base Case
	if (k == 0 or k == n)	return 1;

	// Recursive Case
	return bCoefficient(n - 1, k) + bCoefficient(n - 1, k - 1);
}

long long bCoefficient_dp(const int n, const int k, long long** dp) {
	// Base Case
	if (k == 0 or k == n)	return 1;

	//Dp-Check
	if (dp[n][k])	return dp[n][k];

	// Recursive Case
	return dp[n][k] = bCoefficient_dp(n - 1, k, dp) + bCoefficient_dp(n - 1, k - 1, dp);
}

long long bCoefficient_dp(const int n, const int k) {
	long long **dp;
	dp = new long long*[n + 1];
	for (int i = 0; i < n + 1; i++)
		dp[i] = new long long[k + 1];

	// Initializing dp
	for (int i = 0; i < n + 1; i++)
		for (int j = 0; j < k + 1; j++)
			dp[i][j] = 0;

	return bCoefficient_dp(n, k, dp);
}

// =====================Problem-5===================
double sumOfSequence(const int n) {
	// Base Case
	if (n == 1) return 1.0;

	// Recursive Case
	return	sumOfSequence(n - 1) + ((n % 2) ?  - 1.0 / n : + 1.0 / n);
}


// =====================Problem-6===================
int gcd(int a, int b) {
	//Base Case
	if (b == 0) return a;

	// Recursive Case
	if (a < b)	return gcd(b, a);
	return gcd(b, a % b);
}


// =====================Problem-7===================
void cubes(int n) {
	// Base Case
	if (n == 0)	return;

	// Recursive Case
	cubes(n - 1);
	std::cout << n*n*n << ' ';
	return;
}

int main() {
	std::cout << "\n=====================Problem-1===================\n";
	std::cout << putCommas(1234567) << std::endl;
	std::cout << putCommas(00111222333) << std::endl;
	std::cout << putCommas(600111222333) << std::endl;
	std::cout << "\n=====================Problem-2===================\n";
	syracuseSequence(12);
	std::cout << "--------------------------------\n";
	syracuseSequence(19);
	std::cout << "--------------------------------\n";
	syracuseSequence(27);
	std::cout << "\n=====================Problem-3===================\n";
	std::cout << multiply(3, 4) << std::endl;
	std::cout << multiply(4, 3) << std::endl;
	std::cout << multiply(23, 3) << std::endl;
	std::cout << multiply(89, 43) << std::endl;
	std::cout << "\n=====================Problem-4===================\n";
	std::cout << bCoefficient(5, 4) << std::endl;
	std::cout << bCoefficient(67, 67) << std::endl;
	std::cout << bCoefficient(12, 7) << std::endl;
	// std::cout << bCoefficient(30, 15) << std::endl; // uncommenting this line will add about 2s more in run time
	// std::cout << bCoefficient(32, 15) << std::endl; // uncommenting this line will add about 6-7s more in run time
	// std::cout << bCoefficient(96, 69) << std::endl; // didn't halt
	std::cout << bCoefficient_dp(5, 4) << std::endl;
	std::cout << bCoefficient_dp(67, 67) << std::endl;
	std::cout << bCoefficient_dp(12, 7) << std::endl;
	std::cout << bCoefficient_dp(31, 15) << std::endl; // No problem with dp solution
	std::cout << bCoefficient_dp(32, 15) << std::endl;
	std::cout << bCoefficient_dp(96, 69) << std::endl;
	std::cout << "\n=====================Problem-5===================\n";
	std::cout << sumOfSequence(6) << std::endl;
	std::cout << sumOfSequence(7) << std::endl;
	std::cout << sumOfSequence(5) << std::endl;
	std::cout << sumOfSequence(8) << std::endl;
	std::cout << "\n=====================Problem-6===================\n";
	std::cout << gcd(8, 4) << std::endl;
	std::cout << gcd(4, 8) << std::endl;
	std::cout << gcd(13, 37) << std::endl;
	std::cout << gcd(37264, 357) << std::endl;
	std::cout << "\n=====================Problem-7===================\n";
	cubes(35);

	return 0;
}