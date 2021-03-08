#include <iostream>
using namespace std;
int _blocks(int rows)
{
    if (rows == 0)
        return 0;
    return (rows+(_blocks(rows-1)));
}
int main()
{
    cout << _blocks(7);
    return 0;
}