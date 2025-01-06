#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void helper(string temp, int o, int c, int n, vector<string> &ans)
    {
        if (o == n && c == n)
        {
            ans.push_back(temp);
            return;
        }

        if (o < n)
        {
            helper(temp + "(", o + 1, c, n, ans);
        }

        if (o > c)
        {
            helper(temp + ")", o, c + 1, n, ans);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        helper("", 0, 0, n, ans);
        return ans;
    }
};

int main()
{
    int n = 3;
    Solution sol;
    vector<string> ans = sol.generateParenthesis(n);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}