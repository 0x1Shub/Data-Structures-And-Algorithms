#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int> &arr)
    {
        long long maxiSum = INT_MIN;
        long long sum = 0;
        int start = 0;
        int ansStart = -1, ansEnd = -1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (sum == 0)
            {
                start = i;
            }
            sum += arr[i];

            if (sum > maxiSum)
            {
                maxiSum = sum;
                ansStart = start;
                ansEnd = i;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }

        cout << "The Subarray is : { ";
        for (int i = ansStart; i <= ansEnd; i++)
        {
            cout << arr[i] << " ";
        }
        cout << " }" << endl;

        return maxiSum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << "The max sum is : " << sol.maxSubarraySum(arr) << endl;
    return 0;
}