// Longest Substring Without Repeating Characters

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthSubstr(string s)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_set<char> set;
            for (int j = 1; j < s.size(); j++)
            {
                if (set.find(s[j]) != set.end())
                {
                    maxi = max(maxi, j - i);
                    break;
                }
                set.insert(s[j]);
            }
            return maxi;
        }
    }

    int optimal(string s)
    {
        int ans = INT_MIN;
        unordered_set<char> set;
        int l = 0;
        for (int r = 0; r < s.size(); r++)
        {
            if (set.find(s[r]) != set.end())
            {
                while (l < r && set.find(s[r]) != set.end())
                {
                    set.erase(s[l]);
                    l++;
                }
            }
            set.insert(s[r]);
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

int main()
{
    string s = "takeUforward";
    Solution sol;
    cout << sol.optimal(s) << endl;
    return 0;
}