#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DIVISION_BY_ZERO -1
#define ILLEGAL_OPERATION -2

class Calculator {
    private:
        int a;
        int b;
        char ch;
        int ans;
    public:
        void get_input() {
            cin >> a >> b;
            if (cin.fail()) {
                cin.clear();
                throw DIVISION_BY_ZERO;
            }
            cin >> ch;
        } 
        int add() {
            return a + b;
        }
        int sub() {
            return a - b;
        }
        int mul() {
            return a * b;
        }
        int div() {
            if (b == 0) {
                throw DIVISION_BY_ZERO;
            }
            else {
                return a / b;
            }
        }
        void check_char_show() {
            if (ch == '+') {
                ans = add();
                cout << ans << '\n';
            }
            else if (ch == '-') {
                ans = sub();
                cout << ans << '\n';
            }
            else if (ch == '*') {
                ans = mul();
                cout << ans << '\n';
            }
            else if (ch == '/') {
                ans = div();
                cout << ans << '\n';
            }
            else {
                throw ILLEGAL_OPERATION;
            }
        }
};

int main() {
    int n;
    cin >> n;
    while (n--) {
            try {
            Calculator c;
                 c.get_input();
                 c.check_char_show();
        }
            catch(int t) {
                if (t == DIVISION_BY_ZERO) {
                    cout << "DATA_ERROR\n";
                }
                else if (t == ILLEGAL_OPERATION) {
                    cout << "ILLEGAL_OPERATION\n";
                }
            }
            catch(...) {
                cout << "other error";
            }
    }
    return 0;
}
