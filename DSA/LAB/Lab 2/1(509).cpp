#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

int main() {
	// Input the size of each list
	int list_size; std::cin >> list_size;

	// making dynamic array of 3 arrays of integers
	std::vector< std::vector<int> > lists(3, std::vector<int>(list_size));
	// You Can simply do it like this as well
	// int lists[3][list_size];

	// making dynamic array of 3 arrays of pair of integers and integerss
	std::vector< std::vector< std::pair<int, int> > > sorted_lists(3, std::vector< std::pair<int, int> >(list_size));
	// You Can simply do it like this as well
	// std::pair<int, int> sorted_lists[3][list_size]

	int temp1, temp2, temp3;

	// Reading the input in lists and also maintaining it in a separate sorted list
	for (int i = 0; i < list_size; i++) {
		std::cin >> temp1 >> temp2 >> temp3;
		lists[0][i] = temp1;
		lists[1][i] = temp2;
		lists[2][i] = temp3;

		sorted_lists[0][i] = std::make_pair(temp1, i);
		sorted_lists[1][i] = std::make_pair(temp2, i);
		sorted_lists[2][i] = std::make_pair(temp3, i);
	}


	// Weo sort the "sorted_list"
	std::sort(sorted_lists[0].begin(), sorted_lists[0].end());
	std::sort(sorted_lists[1].begin(), sorted_lists[1].end());
	std::sort(sorted_lists[2].begin(), sorted_lists[2].end());

	//if we comment line 17 and uncomment line 19, then this block of code should work
	/*std::sort(sorted_lists[0], sorted_lists[0] + list_size);
	std::sort(sorted_lists[1], sorted_lists[1] + list_size);
	std::sort(sorted_lists[2], sorted_lists[2] + list_size);*/


	// On every query we print the answer by using both the sorted and original lists
	int queries; std::cin >> queries;
	while (queries--) {
		std::cin >> temp1 >> temp2;
		temp3 = sorted_lists[temp1][temp2].second;

		std::cout << lists[0][temp3] << ' '
		          << lists[1][temp3] << ' '
		          << lists[2][temp3] << '\n';
	}

	return 0;
}