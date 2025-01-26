#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long graph(int n)
    {
        return (long long)pow(2, (n * (n - 1) / 2));
    }
};

int main()
{
    int n = 5;
    Solution sol;
    cout << sol.graph(n) << endl;
    return 0;
}