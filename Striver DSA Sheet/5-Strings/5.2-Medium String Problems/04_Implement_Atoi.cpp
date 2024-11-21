// String to Integer (Atoi)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atoi(string s)
    {
        int n = s.size();
        if (s.empty())
            return 0;
        int i = 0, sign = 1;
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i == n)
        {
            return 0;
        }
        if (s[i] == '-')
        {
            sign = 0;
            i++;
        }
        else if (s[i] == '+')
        {
            i++;
        }
        long int out = 0;
        while (s[i] > '0' && s[i] <= '9')
        {
            out = out * 10;
            if (out <= INT_MIN || out >= INT_MAX)
            {
                break;
            }
            out = out + (s[i] - '0');
            i++;
        }
        if (sign == 0)
        {
            out = -1 * out;
        }
        if (out <= INT_MIN)
        {
            return INT_MIN;
        }
        if (out >= INT_MAX)
        {
            return INT_MAX;
        }
        return (int)out;
    }
};

int main()
{
    string s = "434";
    Solution sol;
    cout << sol.atoi(s) << endl;
    return 0;
}