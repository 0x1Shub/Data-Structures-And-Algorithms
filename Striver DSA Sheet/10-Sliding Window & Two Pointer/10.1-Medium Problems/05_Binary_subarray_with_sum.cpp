#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayWithSum(vector<int> &arr, int k)
    {
        unordered_map<int, int> mpp;
        int currentSum = 0;
        int count = 0;

        mpp[0] = 1;
        for (int num : arr)
        {
            currentSum += num;
            if (mpp.find(currentSum - k) != mpp.end())
            {
                count += mpp[currentSum - k];
            }
            mpp[currentSum]++;
        }

        return count;
    }
};

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1};
    int k = 2;
    Solution sol;
    cout << sol.numSubarrayWithSum(arr, k) << endl;
    return 0;
}
