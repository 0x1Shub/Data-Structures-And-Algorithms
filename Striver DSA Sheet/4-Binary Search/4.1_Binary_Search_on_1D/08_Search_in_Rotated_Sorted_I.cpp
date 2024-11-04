#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int count = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            // If left part sorted
            if (arr[start] <= arr[mid])
            {
                if (arr[start] <= target && target <= arr[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            // If right part sorted
            else
            {
                if (arr[mid] <= target && target <= arr[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int target = 1;
    Solution sol;
    cout << sol.search(arr, target) << endl;
    return 0;
}