#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
	long long n; std::cin >> n;
	std::vector< std::pair<long, long> > houses(n);

	for (int i = 0; i < n; i++) {
		std::cin >> houses[i].first;
		houses[i].second = i + 1;
	}

	sort(houses.begin(), houses.end());

	long long ans[n];
	for (int i = 0; i < n; i++)
		ans[houses[i].second - 1] = i + 1;

	for (int i = 0; i < n; i++)
		std::cout << ans[i] << ' ';
	std::cout << '\n';
	return 0;
}