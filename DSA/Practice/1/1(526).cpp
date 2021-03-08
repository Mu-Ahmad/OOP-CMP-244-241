#include <iostream>
using namespace std;
int _count(long long int n)
{
    int digit,count=0;
    if(n==0)
        return count;
    else
    {
        digit = n%10;
        n=n/10;   
        if (digit == 7)
        {
            count++;
        }
    }
    return count+_count(n);
}
int main()
{
    cout << _count(7777777777);
    return 0;
}