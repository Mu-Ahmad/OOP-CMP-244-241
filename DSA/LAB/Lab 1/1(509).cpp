#include <iostream>
#include <sstream>

class Calcuation {
    int integer1, integer2;
    char operation;

    template<typename T>
    void safeRead(T& dest) {
        std::cin >> dest;

        if (std::cin.fail())    throw "DATA_ERROR";
    }
public:
    void readData() {
        safeRead(integer1);
        safeRead(integer2);
        safeRead(operation);
    }

    void displayResult() const {
        switch (operation) {
        case '+': {
            std::cout << integer1 + integer2 << '\n';
            break;
        }
        case '-': {
            std::cout << integer1 - integer2 << '\n';
            break;
        }
        case '*': {
            std::cout << integer1 * integer2 << '\n';
            break;
        }
        case '/': {
            if (integer2 == 0)    throw "DATA_ERROR";

            std::cout << integer1 / integer2 << '\n';
            break;

        }
        default: throw "ILLEGAL_OPERATION";
        }
    }
};

int main() {
    int n; std::cin >> n;
    Calcuation calculator;

    while (n--) {
        try {
            calculator.readData();
            calculator.displayResult();
        } catch (const char * error_code) {
            std::cout << error_code << '\n';
        } catch (...) {
            std::cout << "Unhandled Exception\n";
        }
    }

    return 0;
}