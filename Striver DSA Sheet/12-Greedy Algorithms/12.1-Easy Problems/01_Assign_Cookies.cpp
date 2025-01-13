#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int assignCookies(vector<int> &g, vector<int> &s)
    {
        int n = g.size();
        int m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;
        while (r < m)
        {
            if (g[l] <= s[r])
            {
                l = l + 1;
            }
            r = r + 1;
        }
        return l;
    }
};

int main()
{
    vector<int> g = {1, 5, 3, 3, 4};
    vector<int> s = {4, 2, 1, 2, 1, 3};
    Solution sol;
    cout << sol.assignCookies(g, s) << endl;
    return 0;
}