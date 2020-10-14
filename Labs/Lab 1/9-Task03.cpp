#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n; cin >> n;
	int _num = 1;
	while (n--) {
		int num = n + 1;
		while (num--)
			cout << _num++ << ' ';
		cout << '\n';
	}
	return 0;
}