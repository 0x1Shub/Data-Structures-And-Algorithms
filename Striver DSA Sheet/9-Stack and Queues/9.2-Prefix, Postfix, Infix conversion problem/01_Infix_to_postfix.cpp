#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int prec(char c)
    {
        if (c == '^')
        {
            return 3;
        }
        else if (c == '/' || c == '*')
        {
            return 2;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }

    void infixToPostfix(string s)
    {
        stack<char> st;
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            {
                ans += ch;
            }
            else if (ch == '(')
            {
                st.push('(');
            }
            else if (ch == ')')
            {
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while (!st.empty() && prec(s[i]) <= prec(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        cout << "Prefix expression: " << ans << endl;
    }
};

int main()
{

    string s = "(p+q)*(m-n)";
    cout << "Infix expression: " << s << endl;
    Solution sol;
    sol.infixToPostfix(s);
    return 0;
}