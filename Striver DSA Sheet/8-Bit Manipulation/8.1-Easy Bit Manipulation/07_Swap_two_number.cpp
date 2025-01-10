#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    pair<int, int> swapNum(int a, int b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
        return {a, b};
    }
};

int main()
{
    int a = 14;
    int b = 9;
    Solution sol;
    pair<int, int> ans = sol.swapNum(a, b);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}