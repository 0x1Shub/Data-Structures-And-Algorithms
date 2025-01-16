// maximum number of nodes on level i of a binary tree

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countNodes(int i)
    {
        int ans = pow(2, i - 1);
        return ans;
    }
};

int main()
{
    int i = 5;
    Solution sol;
    cout << sol.countNodes(i) << endl;
    return 0;
}