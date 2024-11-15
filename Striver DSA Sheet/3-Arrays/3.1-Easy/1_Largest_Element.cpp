#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestElement(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxi)
            {
                maxi = arr[i];
            }
        }
        return maxi;
    }
};

int main()
{
    vector<int> arr = {2, 5, 1, 3, 0};
    Solution sol;
    cout << sol.largestElement(arr) << endl;
    return 0;
}