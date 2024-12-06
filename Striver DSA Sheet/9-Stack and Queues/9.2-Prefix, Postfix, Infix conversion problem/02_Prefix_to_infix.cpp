#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string prefixToInfix(string pre_exp)
    {
        stack<string> st;
        for (int i = pre_exp.length() - 1; i >= 0; i--)
        {
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                st.push(string(1, pre_exp[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string temp = '(' + t1 + pre_exp[i] + t2 + ')';
                st.push(temp);
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
    string ans = sol.prefixToInfix(s);
    cout << "Infix expression: " << ans << endl;
    return 0;
}