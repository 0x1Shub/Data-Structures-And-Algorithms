// Search Insert Position

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsertPosition(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] >= target)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 7};
    int target = 6;
    Solution sol;
    cout << sol.searchInsertPosition(arr, target) << endl;
    return 0;
}