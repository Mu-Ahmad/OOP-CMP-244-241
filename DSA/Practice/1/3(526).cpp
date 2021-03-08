#include <iostream>
using namespace std;
bool array220(int a[], int n, int idx = 0)
{
    bool option = false;
    if (idx == n - 1)
    {
        if (a[idx] * 10 == a[n - 1])
            return true;
        return false;
    }
    else if (idx < n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[idx] * 10 == a[i])
            {
                option = true;
            }
        }
        idx++;
    }
    return option || array220(a, n, idx);
}
int main()
{
    int a[7] = {1, 2, 50,4,50,30,7};
    int n = 7;
    if (array220(a, n))
    {
        cout << "TRUE";
    }
    else
    {
        cout << "FALSE";
    }

    return 0;
}