// Check if two Strings are anagrams of each other

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkAnagram(string s1, string s2)
    {
        if (s1.length() != s2.length())
            return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                return false;
        }
        return true;
    }
};

int main()
{
    string s1 = "INTEGER";
    string s2 = "TEGERNI";
    Solution sol;
    cout << sol.checkAnagram(s1, s2) << endl;
    return 0;
}