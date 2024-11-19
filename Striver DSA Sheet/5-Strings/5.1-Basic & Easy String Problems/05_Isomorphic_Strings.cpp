#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphicString(string s, string t)
    {
        int map_s[256] = {0};
        int map_t[256] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            if (map_s[s[i]] != map_t[t[i]])
            {
                return false;
            }
            map_s[s[i]] = i + 1;
            map_t[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{
    string s = "egg";
    string t = "add";
    Solution sol;
    cout << sol.isIsomorphicString(s, t) << endl;
    return 0;
}