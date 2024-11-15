#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int secondLargest(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = INT_MIN;
        int second_maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > maxi)
            {
                second_maxi = maxi;
                maxi = arr[i];
            }
            if (arr[i] != maxi && arr[i] > second_maxi)
            {
                second_maxi = arr[i];
            }
        }
        return second_maxi;
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 7, 7, 5};
    Solution sol;
    cout << sol.secondLargest(arr) << endl;
    return 0;
}