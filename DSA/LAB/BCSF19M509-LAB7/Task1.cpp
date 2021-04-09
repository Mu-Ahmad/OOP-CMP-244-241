/*
Name: Muhammad Ahmad
Roll: BCSF19M509
*/

#include <iostream>
#include "Stack.cpp"

using namespace std;


int main() {
	/*
	int n=8;
	int arr[n] = {-1, 23, 59, 37, -1, 46, 64, -1};
	*/
	cout << "Enter number of Elements in big list (including -1): ";
	int n; 	cin >> n;
	cout << "Enter lists separated by -1 :\n";
	// We can input directly in stack as well;
	int arr[n];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	Stack <int> stack_lists(n);
	for (int i = 0; i < n; i++)
		stack_lists.push(arr[i]);

	stack_lists.pop();// Ignoring the last -1
	Stack <int> another_stack(n);
	int temp;
	while (!stack_lists.isEmpty()) {
		temp = stack_lists.pop();
		if (temp == -1) {

			while (!another_stack.isEmpty()) {
				cout << another_stack.pop() << ' ';
			}
			cout << '\n';
		} else another_stack.push(temp);
	}

	return 0;
}
