// Kadane's Algorithm : Maximum Subarray Sum in an Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int SubarraySum(vector<int> &arr)
    {
        int maxSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < arr.size(); j++)
            {
                sum += arr[j];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }

    int optimal(vector<int> &arr)
    {
        int maxiSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum = sum + arr[i];
            if (sum < 0)
            {
                sum = 0;
            }
            maxiSum = max(maxiSum, sum);
        }
        return maxiSum;
    }
};

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << "The maximum subarray sum is: " << sol.optimal(arr) << endl;
    return 0;
}