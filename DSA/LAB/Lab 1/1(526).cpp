#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define DATA_ERROR -1
#define ILLEGAL_OPERATION -2

class calculator
{
private:
    int a, b, result;
    char opr;

public:
    calculator(int a, int b, char opr)
    {
        setter(a, b, opr);
    }
    void setter(int a, int b, char opr)
    {
        cin >> a >> b >> opr;
        this->a = a;
        this->b = b;
        this->opr = opr;
        if (cin.fail())
            throw DATA_ERROR;
    }
    int sum()
    {
        return a + b;
    }
    int sub()
    {
        return a - b;
    }
    int div()
    {
        if (b > 0)
            return a / b;
        throw DATA_ERROR;
    }
    int mul()
    {
        return a * b;
    }
    bool validOperator()
    {
        if (opr == '+' || opr == '-' || opr == '*' || opr == '/')
            return true;
        return false;
    }
    int getresult()
    {
        if (validOperator())
        {
            if (opr == '+')
                result = sum();
            else if (opr == '-')
                result = sub();
            else if (opr == '*')
                result = mul();
            else if (opr == '/')
                result = div();
            return result;
        }
        throw ILLEGAL_OPERATION;
    }
};

int main()
{
    int n=7;
    while (n != 0)
    {
        try
        {
            int a, b;
            char opr;
            calculator cal(a, b, opr);
            cout << cal.getresult() << endl;
        }
        catch (int type)
        {
            if (type == DATA_ERROR)
                cout << "DATA_ERROR\n";
            else if (type == ILLEGAL_OPERATION)
                cout << "ILLEGAL_OPERATION\n";
        }
        n--;
    }

    return 0;
}
