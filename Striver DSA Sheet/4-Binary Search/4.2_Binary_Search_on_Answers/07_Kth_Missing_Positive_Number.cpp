#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingK(vector<int> &arr, int k)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] <= k)
            {
                k++;
            }
            else
            {
                break;
            }
        }
        return k;
    }

    int optimal(vector<int> &arr, int k)
    {
        int start = 0;
        int end = arr.size() - 1;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int missing = arr[mid] - (mid + 1);
            if (missing < k)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return k + end + 1;
    }
};

int main()
{
    vector<int> arr = {4, 7, 9, 10};
    int k = 4;
    Solution sol;
    cout << "Kth Missing Number: " << sol.optimal(arr, k) << endl;
    return 0;
}