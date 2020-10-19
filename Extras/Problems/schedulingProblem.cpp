#include <iostream>

bool solve(int s, int *p, int n, int k) {
	int count = 0;

	for (int i = 0; i < n; i++)
		count += s / p[i]; //Accumalting the work of individual work of a machine

	//Return true if given work can be achieved by given machines in given time
	return count >= k;
}

int main() {
	//Taking input
	int n; std::cin >> n;
	int p[n + 1];
	for (int i = 0; i < n; i++) std::cin >> p[i];
	int k; std::cin >> k;
	int z = p[0] * k, x = -1;

	//This loops normalize the solve function to the minimum parameters for which it returns true
	for (int i = z; i > 0; i /= 2)
		while (!solve(x + i, p, n, k)) x += i;

	std::cout << x + 1 << '\n';
	return 0;
}

/*
n = 3
p = {2, 3, 7}
k = 7
ans = 8
*/

/*
n = 3
p = {2, 3, 7}
k = 8
ans = 9
*/

/*
n = 5
p = {4, 3, 5, 6, 8}
k = 33
ans = 32
*/