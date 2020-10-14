#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#define mp   make_pair
using namespace std;

//Need no explanation

int main() {
    vector <pair<int, pair<int, pair<int, int>>>> array;
    int rows , cols; cin >> rows >> cols;
    int temp, pos = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> temp;
            array.push_back(mp(temp, mp(pos, (mp(i + 1, j + 1)))));
            pos++;
        }
    }
    sort(array.begin(), array.end());
    int k = 1;
    for (int i = 0; i < rows * cols; i += k) {
        k = 1;
        while (array[i].second.first == array[i + k].second.first - k)
            k++;
        cout << array[i].second.second.first << ' ' << array[i].second.second.second <<
             ' ' << k << '\n';
    }

    return 0;
}
