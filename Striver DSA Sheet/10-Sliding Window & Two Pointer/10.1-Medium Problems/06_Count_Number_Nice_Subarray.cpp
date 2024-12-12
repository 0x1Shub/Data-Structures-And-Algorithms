#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixCount;
        int currentOddCount = 0;
        int result = 0;
        prefixCount[0] = 1;

        for (int num : nums)
        {
            if (num % 2 != 0)
            {
                currentOddCount++;
            }
            if (prefixCount.find(currentOddCount - k) != prefixCount.end())
            {
                result += prefixCount[currentOddCount - k];
            }
            prefixCount[currentOddCount]++;
        }

        return result;
    }
};

int main()
{
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    Solution sol;
    int result = sol.numberOfSubarrays(nums, k);
    cout << "Number of nice subarrays: " << result << endl;
    return 0;
}
