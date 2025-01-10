#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main()
{
    int n = 16;
    Solution sol;
    if (sol.isPowerOfTwo(n))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}