// The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int upperBound(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] > target)
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
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int target = 9;
    Solution sol;
    cout << sol.upperBound(arr, target) << endl;
    return 0;
}