// Longest Subarray with given Sum K(Positives)\

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

    int optimal(vector<int> &arr, int k)
    {
        int n = arr.size();
        int left = 0, right = 0;
        long long sum = arr[0];
        int len = 0;
        while (right < n)
        {
            while (left <= right && sum > k)
            {
                sum -= arr[left];
                left++;
            }
            if (sum == k)
            {
                len = max(len, right - left + 1);
            }
            right++;
            if (right < n)
            {
                sum += arr[right];
            }
        }
        return len;
    }
};

int main()
{
    vector<int> arr = {2, 3, 5, 1, 9};
    int k = 10;
    Solution sol;
    cout << sol.optimal(arr, k) << endl;
    return 0;
}