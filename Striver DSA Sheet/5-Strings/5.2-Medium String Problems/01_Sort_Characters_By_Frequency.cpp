#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mpp;
        for (char ch : s)
        {
            mpp[ch]++;
        }
        sort(s.begin(), s.end(),
             [&mpp](const char a, const char b)
             {
                 return (mpp[a] == mpp[b]) ? a < b : mpp[a] > mpp[b];
             });
        return s;
    }
};

int main()
{
    string s = "tree";
    Solution sol;
    cout << sol.frequencySort(s) << endl;
    return 0;
}