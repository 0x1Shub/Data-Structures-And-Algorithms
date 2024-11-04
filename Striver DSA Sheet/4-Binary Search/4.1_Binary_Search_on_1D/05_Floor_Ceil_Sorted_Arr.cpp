// The floor of x is the largest element in the array which is smaller than or equal to x( i.e. largest element in the array <= x).
// The ceiling of x is the smallest element in the array greater than or equal to x( i.e. smallest element in the array >= x).

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getFloor(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] <= target)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ans;
    }

    int getCeil(vector<int> &arr, int target)
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

    pair<int, int> getFloorCeil(vector<int> &arr, int target)
    {
        int n = arr.size();
        int f = getFloor(arr, target);
        int c = getCeil(arr, target);
        return make_pair(f, c);
    }
};

int main()
{
    vector<int> arr = {3, 4, 4, 7, 8, 10};
    int target = 5;
    Solution sol;
    pair<int, int> ans = sol.getFloorCeil(arr, target);
    cout << "The floor and ceil are: " << ans.first
         << " " << ans.second << endl;
    return 0;
}