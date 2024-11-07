#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string compare(int n, int m)
    {
        if (n < m)
        {
            return "Lesser";
        }
        else if (n == m)
        {
            return "Equal";
        }
        else
        {
            return "Greater";
        }
    }
};

int main()
{
    int n;
    int m;
    cin >> n >> m;
    Solution sol;
    cout << sol.compare(n, m) << endl;
    return 0;
}