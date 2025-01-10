#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int setBit(int n)
    {
        int y = ~n;
        y = y & y - 1;
        return ~y;
    }
};

int main()
{
    int n = 15;
    Solution sol;
    cout << sol.setBit(n) << endl;
    return 0;
}