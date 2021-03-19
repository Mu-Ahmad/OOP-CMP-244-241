#include <bits/stdc++.h>

bool solve(int n, int x) {
    // Base Case
    if (x == n)
        return true;
    if (n > x)
        return false;
    // Recursive Case
    return solve(n * 20, x) or solve(n * 10, x);
}

int main() {
    int t; std::cin >> t;
    int x;
    while (t--) {
        std::cin >> x;
        (solve(1, x)) ? std::cout << "Yes\n" : std::cout << "No\n";
    }
    return 0;
}