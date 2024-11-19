#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestOddNumber(string s)
    {
        for (int i = s.size() - 1; i >= 0; i--)
        {
            char c = s[i];
            if (c % 2 != 0)
            {
                return s.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main()
{
    string s = "891239";
    Solution sol;
    cout << sol.largestOddNumber(s) << endl;
    return 0;
}