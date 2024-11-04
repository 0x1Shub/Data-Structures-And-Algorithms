// Duplicate values contains in array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchII(vector<int> &arr, int target)
    {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target)
            {
                return true;
            }

            if (arr[start] == arr[mid] && arr[mid] == arr[end])
            {
                start = start + 1;
                end = end - 1;
                continue;
            }

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
        return false;
    }
};

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    Solution sol;
    cout << sol.searchII(arr, target) << endl;
    return 0;
}