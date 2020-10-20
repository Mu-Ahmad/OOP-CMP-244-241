#include <iostream>
#include <algorithm>


struct movieTime {
	int start, end;
};

bool compare(movieTime x, movieTime y) {
	return (x.end < y.end);
}

int main() {
	//Reading input
	int n; std::cin >> n;
	movieTime timings[n]; //<end, start>
	for (int i = 0; i < n; i++)
		std::cin >> timings[i].start >> timings[i].end; // <end, start>

	//Using Sort from algorithm header and comparater(compare) for our struct movieTime that sorts the movies on the basis of their ending time
	std::sort(timings, timings + n, compare);

	// To keep count of the movies checked and ending time of the current running movie
	int end = 0, count = 0;
	for (int i = 0; i < n; i++)
		if (timings[i].start >= end) {
			count++;
			end = timings[i].end;
		}
	//Printing answer.....
	std::cout << count << '\n';

	return 0;
}

/*
Input:
10
6 7
4 5
8 9
2 3
10 11
1 2
9 10
3 4
5 6
7 8
ans = 10
*/

/*
10
404 882
690 974
201 255
800 933
525 819
457 601
461 978
832 932
699 804
795 860
ans = 4
*/

