#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeOutermostParentheses(string s)
    {
        string ans;
        stack<char> st;
        for (auto it : s)
        {
            if (it == '(')
            {
                if (!st.empty())
                {
                    ans.push_back(it);
                }
                st.push(it);
            }
            else
            {
                st.pop();
                if (!st.empty())
                {
                    ans.push_back(it);
                }
            }
        }
        return ans;
    }
};

int main()
{
    string s = "(()())(())";
    Solution sol;
    cout << sol.removeOutermostParentheses(s) << endl;
    return 0;
}