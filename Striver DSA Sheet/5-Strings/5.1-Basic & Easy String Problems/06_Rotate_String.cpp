#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool rotateStrings(string s, string goal)
    {
        if (s == goal)
        {
            return true;
        }
        string rotate = "";
        for (int i = 0; i < s.size() - 1; i++)
        {
            rotate.append(s, i + 1, s.size() - i + 1);
            rotate.append(s, 0, i + 1);
            if (rotate == goal)
            {
                return true;
            }
            else
            {
                rotate = "";
            }
        }
        return false;
    }
};

int main()
{
    string s = "abcde";
    string goal = "cdeab";
    Solution sol;
    cout << sol.rotateStrings(s, goal) << endl;
    return 0;
}