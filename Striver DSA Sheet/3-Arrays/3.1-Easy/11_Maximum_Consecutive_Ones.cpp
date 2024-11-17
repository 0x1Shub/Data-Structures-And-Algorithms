#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxConsecutiveOnes(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            maxi = max(maxi, count);
        }
        return maxi;
    }
};

int main()
{
    vector<int> arr = {1, 1, 0, 1, 1, 1};
    Solution sol;
    cout << sol.maxConsecutiveOnes(arr) << endl;
    return 0;
}