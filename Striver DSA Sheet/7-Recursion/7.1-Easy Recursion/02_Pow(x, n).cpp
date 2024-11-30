// Implement Pow(x,n) | X raised to the power N

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;
        if (n == 0)
        {
            return ans;
        }
        if (n < 0)
        {
            x = 1 / x;
            n = -1 * n;
        }
        double half = myPow(x, n / 2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else
        {
            return half * half * x;
        }
    }
};

int main()
{
    double x = 2.000;
    int n = 10;
    Solution sol;
    cout << sol.myPow(x, n) << endl;
    return 0;
}