#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool is_negative = (dividend < 0) ^ (divisor < 0);
        long long abs_dividend = abs((long long)dividend);
        long long abs_divisor = abs((long long)divisor);

        long long quotient = 0;
        for (int i = 31; i >= 0; --i)
        {
            if ((abs_dividend >> i) >= abs_divisor)
            {
                abs_dividend -= abs_divisor << i;
                quotient += 1LL << i;
            }
        }
        quotient = is_negative ? -quotient : quotient;
        if (quotient > INT_MAX)
            return INT_MAX;
        if (quotient < INT_MIN)
            return INT_MIN;

        return quotient;
    }
};

int main()
{
    int divident = 10;
    int divisor = 3;
    Solution sol;
    cout << sol.divide(divident, divisor) << endl;
    return 0;
}