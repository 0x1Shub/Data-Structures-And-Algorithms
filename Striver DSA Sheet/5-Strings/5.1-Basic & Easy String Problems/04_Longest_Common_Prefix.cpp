#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &s)
    {
        string ans = "";

        for (int i = 0; i < s[0].size(); i++)
        {
            char ch = s[0][i];
            bool match = true;

            for (int j = 1; j < s.size(); j++)
            {
                if (s[j].size() < i || ch != s[j][i])
                {
                    match = false;
                    break;
                }
            }
            if (match == false)
            {
                break;
            }
            else
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> s = {"flower", "flow", "flight"};
    Solution sol;
    cout << sol.longestCommonPrefix(s) << endl;
    return 0;
}