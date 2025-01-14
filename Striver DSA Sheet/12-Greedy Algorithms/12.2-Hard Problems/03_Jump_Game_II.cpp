#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jumpGame(vector<int> &nums)
    {
        int n = nums.size();
        int jumps = 0, current_end = 0, farthest = 0;

        for (int i = 0; i < n - 1; ++i)
        {
            farthest = max(farthest, i + nums[i]);
            if (i == current_end)
            {
                ++jumps;
                current_end = farthest;
            }
        }
        return jumps;
    }
};

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution sol;
    int ans = sol.jumpGame(nums);
    cout << ans << endl;
    return 0;
}