#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postfixToInfix(string exp)
    {
        int n = exp.length();
        stack<string> st;

        for (int i = 0; i < n; i++)
        {
            char ch = exp[i];

            if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
            {
                st.push(string(1, ch));
            }
            else if (ch == ' ')
            {
                // Ignore spaces
                continue;
            }
            else
            {
                if (st.size() < 2)
                {
                    cout << "Invalid postfix expression\n";
                    return "";
                }

                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                st.push("(" + t2 + exp[i] + t1 + ")");
            }
        }

        if (st.size() != 1)
        {
            cout << "Invalid postfix expression\n";
            return "";
        }

        return st.top();
    }
};

int main()
{
    string s = "ab*c+";
    cout << "Postfix expression: " << s << endl;
    Solution sol;
    string ans = sol.postfixToInfix(s);
    if (ans != "")
    {
        cout << "Infix expression: " << ans << endl;
    }
    return 0;
}
