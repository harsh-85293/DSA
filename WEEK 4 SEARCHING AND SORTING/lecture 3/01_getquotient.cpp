// find quotient without using / and % using search space
#include <bits/stdc++.h>
using namespace std;

int getquotient(int dividend, int divisor)
{
    int start = 0;
    int end = dividend;
    int mid = start + ((end - start) >> 1);
    int ans = -1;

    while (start <= end)
    {
        if ((divisor * mid) == dividend)
        {
            return mid;
        }

        else if ((divisor * mid) < dividend) // store and compute
        {
            ans = mid;
            start = mid + 1;
        }

        else
        {
            end = mid - 1;
        }

        mid = start + ((end - start) >> 1);
    }
    return ans;
}

int main()
{
    int dividend = -10;
    int divisor = 2;

    int ans = getquotient(abs(dividend), abs(divisor));

    // for handling negative values
    if ((divisor) < 0 && (dividend) > 0 || (divisor) > 0 && (dividend) < 0)
    {
        ans = 0 - ans;
    }

    cout << "final answer is: s" << ans << endl;

    return 0;
}