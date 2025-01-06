// Power Set: Print all the possible subsequences of the String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // bit manipulation
    vector<string> allPossibleStrings(string s)
    {
        int n = s.length();
        vector<string> ans;
        for (int i = 0; i < (1 << n); i++)
        {
            string temp = "";
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                {
                    temp += s[j];
                }
            }
            if (temp.length() > 0)
            {
                ans.push_back(temp);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

    // recursion & backtracking

    void solve(int i, string s, string &str)
    {
        if (i == s.length())
        {
            cout << str << " ";
            return;
        }
        str = str + s[i];
        solve(i + 1, s, str);

        str.pop_back();
        solve(i + 1, s, str);
    }
};

int main()
{
    string s = "abc";
    string str = "";
    Solution sol;
    vector<string> ans = sol.allPossibleStrings(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "All possible subsequences are: " << endl;
    sol.solve(0, s, str);
    return 0;
}