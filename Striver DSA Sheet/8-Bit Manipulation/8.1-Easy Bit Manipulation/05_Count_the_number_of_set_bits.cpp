#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int powerOf2(int n)
    {
        int x = 0;
        while ((1 << x) <= n)
        {
            x++;
        }
        return x - 1;
    }

    int countSetBits(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        int y = powerOf2(n);
        int bitsupto2restox = y * (1 << (y - 1));
        int twoton = (n - (1 << y)) + 1;
        int rest = (n - (1 << y));
        int ans = bitsupto2restox + twoton + countSetBits(rest);
        return ans;
    }
};

int main()
{
    int n = 4;
    Solution sol;
    cout << sol.countSetBits(n) << endl;
    return 0;
}