// Maximum Consecutive ones by flipping at most k elements

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOnes(vector<int> &arr, int k)
    {
        int l = 0, r = 0;
        int zeros = 0;
        int maxLen = 0;
        while (r < arr.size())
        {
            if (arr[r] == 0)
            {
                zeros++;
            }
            if (zeros > k)
            {
                if (arr[l] == 0)
                {
                    zeros--;
                }
                l++;
            }
            if (zeros <= k)
            {
                int len = r - l + 1;
                maxLen = max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }
};

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    Solution sol;
    cout << sol.maxOnes(arr, k) << endl;
    return 0;
}