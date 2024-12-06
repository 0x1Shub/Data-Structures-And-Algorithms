#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string prefixToPostfix(string s)
    {
        stack<string> st;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char ch = s[i];
            if (isalpha(ch))
            {
                st.push(string(1, ch));
            }

            else
            {
                string operand1 = st.top();
                st.pop();
                string operand2 = st.top();
                st.pop();

                string new_exp = operand1 + operand2 + ch;
                st.push(new_exp);
            }
        }
        return st.top();
    }
};

int main()
{
    string s = "*-A/BC-/AKL";
    cout << "Prefix expression: " << s << endl;
    Solution sol;
    string ans = sol.prefixToPostfix(s);
    cout << "Postfix expression: " << ans << endl;
    return 0;
}