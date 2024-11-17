// Longest Subarray with sum K | [Postives and Negatives]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int len = 0;
        for (int i = 0; i < n; i++)
        {
            long long sum = 0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum == k)
                {
                    len = max(len, j - i + 1);
                }
            }
        }
        return len;
    }

    // Using Hashing
    int optimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        map<int, int> mpp;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            int rem = sum - k;
            if (mpp.find(rem) != mpp.end())
            {
                int len = i - mpp[rem];
                maxLen = max(maxLen, len);
            }

            if (mpp.find(sum) == mpp.end())
            {
                mpp[sum] = i;
            }
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {-1, 1, 1};
    int k = 1;
    Solution sol;
    cout << sol.optimal(arr, k) << endl;
    return 0;
}