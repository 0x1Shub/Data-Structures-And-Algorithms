#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int priority(char op)
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    string infixToPostfix(string s)
    {
        string ans;
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            // If it is an operand
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9'))
            {
                ans += s[i];
            }
            // If it is an opening bracket
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }

            // If it is a closing bracket
            else if (s[i] == ')')
            {
                while (!st.empty() && st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            // If it is an operator
            else
            {
                while (!st.empty() && priority(st.top()) >= priority(s[i]))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{
    string s = "A*(B+C)/D";
    cout << "Infix expression: " << s << endl;
    Solution sol;
    string ans = sol.infixToPostfix(s);
    cout << "Prefix expression: " << ans << endl;
    return 0;
}