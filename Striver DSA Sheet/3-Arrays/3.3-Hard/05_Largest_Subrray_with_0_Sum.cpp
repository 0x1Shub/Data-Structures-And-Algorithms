#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarray(vector<int> &arr)
    {
        int maxLen = 0;
        unordered_map<int, int> mpp;
        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            sum += arr[i];

            if (sum == 0)
            {
                maxLen = i + 1;
            }
            else if (mpp.find(sum) != mpp.end())
            {
                maxLen = max(maxLen, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {9, -3, 3, -1, 6, -5};
    Solution sol;
    cout << sol.subarray(arr) << endl;
    return 0;
}