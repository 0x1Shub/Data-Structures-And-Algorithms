#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void recursion(int i, int n)
    {
        if (i > n)
        {
            return;
        }
        cout << i << endl;
        recursion(i + 1, n);
    }
};

int main()
{
    int n = 10;
    Solution sol;
    sol.recursion(1, n);
    return 0;
}