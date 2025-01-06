#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsetPresentRecursive(int n, int k, vector<int> &a, int index = 0)
    {
        if (k == 0)
        {
            return true;
        }
        if (index == n || k < 0)
        {
            return false;
        }
        bool exclude = isSubsetPresentRecursive(n, k, a, index + 1);
        bool include = isSubsetPresentRecursive(n, k - a[index], a, index + 1);
        return exclude || include;
    }

    bool isSubsetPresent(int n, int k, vector<int> &a)
    {
        return isSubsetPresentRecursive(n, k, a);
    }
};

int main()
{
    int n = 3;
    vector<int> arr = {1, 2, 3};
    int k = 5;
    Solution sol;
    if (sol.isSubsetPresent(n, k, arr) == true)
    {
        cout << "Present " << endl;
    }
    else
    {
        cout << "Absent" << endl;
    }
    return 0;
}