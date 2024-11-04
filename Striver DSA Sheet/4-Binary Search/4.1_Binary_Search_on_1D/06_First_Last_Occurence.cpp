#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstocc(vector<int> &arr, int key)
    {
        int size = arr.size();
        int start = 0;
        int end = size - 1;

        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (arr[mid] < key)
            {
                start = mid + 1;
            }
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
        }
        return ans;
    }
    int lastocc(vector<int> &arr, int key)
    {
        int size = arr.size();
        int start = 0;
        int end = size - 1;
        int ans = -1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (arr[mid] == key)
            {
                ans = mid;
                start = mid + 1;
            }
            else if (arr[mid] < key)
            {
                start = mid + 1;
            }
            else if (arr[mid] > key)
            {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int target = 8;

    Solution sol;
    cout << sol.firstocc(arr, target) << endl;
    cout << sol.lastocc(arr, target) << endl;

    return 0;
}