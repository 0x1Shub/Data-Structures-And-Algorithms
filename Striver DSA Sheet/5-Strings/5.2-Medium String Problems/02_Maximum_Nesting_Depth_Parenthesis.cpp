#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int n = s.size();
        int ans = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                c++;
            }
            else if (s[i] == ')')
            {
                c--;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    Solution sol;
    cout << sol.maxDepth(s) << endl;
    return 0;
}