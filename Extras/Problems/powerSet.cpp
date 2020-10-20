#include <iostream>
#define MAX_SIZE 1000

//Global Decleration Area
int include[MAX_SIZE] = {0};

void powerSet(int * set, int size, int k) {
	//Base case
	if (size == k) {
		for (int i = 0; i < size; i++)
			if (include[i]) //Printing out the included elements [Read recursive case before this].
				std::cout << set[i] << ' ';
		std::cout << '\n';
		return;
	}

	//Recursive Case
	/*Wehave two choices, we can either include an element or not, we do both ofcourse*/
	include[k] = 0;
	powerSet(set, size, k + 1);
	include[k] = 1;
	powerSet(set, size, k + 1);
}

int main() {
	//Reading Input
	int n; std::cin >> n;
	int set[n];
	for (int i = 0; i < n; i++)
		std::cin >> set[i];

	//Calling the sub routine that recursively prints out all the subsets one by one
	powerSet(set, n, 0);
	return 0;
}


/*
input:
3
3 6 7
output:

7
6
6 7
3
3 7
3 6
3 6 7
*/

/*
input:
4
1 2 3 4
output:

4
3
3 4
2
2 4
2 3
2 3 4
1
1 4
1 3
1 3 4
1 2
1 2 4
1 2 3
1 2 3 4
*/