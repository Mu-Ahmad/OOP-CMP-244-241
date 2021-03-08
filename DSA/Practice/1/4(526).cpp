#include <iostream>
using namespace std;
long long int _sum(long long int n)
{
    long long int sum=0;
    if(n==0)
        return sum;
    else
    {
        sum += n%10;
        n=n/10;
    }
    return sum+_sum(n); 
}
int main()
{
    cout << _sum(10000000000000);
    return 0;
}