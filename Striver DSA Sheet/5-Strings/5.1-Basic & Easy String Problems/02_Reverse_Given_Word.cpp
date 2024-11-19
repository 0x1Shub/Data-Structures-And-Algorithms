// Reverse Words in a String & Palindrome Check in String

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseString(string s)
    {
        s += " ";
        stack<string> st;
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                st.push(str);
                str = "";
            }
            else
            {
                str += s[i];
            }
        }

        string ans = "";
        while (st.size() != 1)
        {
            ans += st.top() + " ";
            st.pop();
        }
        ans = ans + st.top();

        return ans;
    }

    // Optimized Approach
    string optimal(string s)
    {
        int n = s.size();
        int left = 0;
        int right = n - 1;

        string ans = "";
        string temp = "";

        while (left <= right)
        {
            char ch = s[left];
            if (ch != ' ')
            {
                temp += ch;
            }
            else if (ch == ' ')
            {
                if (ans != "")
                {
                    ans = temp + " " + ans;
                }
                else
                    ans = temp;
                temp = "";
            }
            left++;
        }
    }
};

int main()
{
    string s = "this is an amazing program";
    Solution sol;
    cout << sol.reverseString(s) << endl;
    return 0;
}