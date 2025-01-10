#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkKthBit(int n, int k)
    {
        int bit = n >> k;
        return bit & 1;
    }
};

int main()
{
    int n = 4;
    int k = 0;
    Solution sol;
    if (sol.checkKthBit(n, k))
    {
        cout << "Set" << endl;
    }
    else
    {
        cout << "Unset" << endl;
    }
    return 0;
}