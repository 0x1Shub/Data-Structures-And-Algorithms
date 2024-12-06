#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string postfixToPrefix(string s)
    {
        stack<string> st;
        for (char ch : s)
        {
            if (isalpha(ch))
            {
                st.push(string(1, ch));
            }
            else
            {
                string operand2 = st.top();
                st.pop();
                string operand1 = st.top();
                st.pop();

                string new_exp = ch + operand1 + operand2;
                st.push(new_exp);
            }
        }
        return st.top();
    }
};

int main()
{
    string s = "ABC/-AK/L-*";
    cout << "Postfix expression: " << s << endl;
    Solution sol;
    string ans = sol.postfixToPrefix(s);
    cout << "Prefix expression: " << ans << endl;
    return 0;
}