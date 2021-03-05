#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

int main() {
	long long list_size; std::cin >> list_size;
	std::vector< std::vector<long long> > lists(3, std::vector<long long>(list_size));
	std::vector< std::vector< std::pair<long long, long long> > > sorted_lists(3, std::vector< std::pair<long long, long long> >(list_size));

	long long temp1, temp2, temp3;

	for (long long i = 0; i < list_size; i++) {
		std::cin >> temp1 >> temp2 >> temp3;
		lists[0][i] = temp1;
		lists[1][i] = temp2;
		lists[2][i] = temp3;

		sorted_lists[0][i].first = temp1;
		sorted_lists[1][i].first = temp2;
		sorted_lists[2][i].first = temp3;

		sorted_lists[0][i].second = i;
		sorted_lists[1][i].second = i;
		sorted_lists[2][i].second = i;
	}

	std::sort(sorted_lists[0].begin(), sorted_lists[0].end());
	std::sort(sorted_lists[1].begin(), sorted_lists[1].end());
	std::sort(sorted_lists[2].begin(), sorted_lists[2].end());

	long long queries; std::cin >> queries;
	while (queries--) {
		std::cin >> temp1 >> temp2;
		temp3 = sorted_lists[temp1][temp2].second;

		std::cout << lists[0][temp3] << ' '
		          << lists[1][temp3] << ' '
		          << lists[2][temp3] << '\n';
	}

	return 0;
}