#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<int> &arr, int target, int &ans, int curr, int i)
    {
        if (i == arr.size())
            return;
        solve(arr, target, ans, curr, i + 1);

        if (curr + arr[i] < target)
        {
            solve(arr, target, ans, curr + arr[i], i + 1);
        }

        else if (curr + arr[i] == target)
        {
            ans++;
            solve(arr, target, ans, curr + arr[i], i + 1);
            return;
        }
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int ans = 0;
        solve(arr, target, ans, 0, 0);
        if (target == 0)
            return ans + 1;
        return ans;
    }
};

int main()
{
    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;
    Solution sol;
    int ans = sol.perfectSum(arr, target);
    cout << ans << endl;
    return 0;
}