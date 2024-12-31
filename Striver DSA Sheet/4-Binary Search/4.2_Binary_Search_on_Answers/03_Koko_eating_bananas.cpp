#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMax(vector<int> &v)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < v.size(); i++)
        {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }

    int calculateTotalHrs(vector<int> &v, int hourly)
    {
        int totalH = 0;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            totalH += ceil((double)(v[i]) / (double)(hourly));
        }
        return totalH;
    }

    int minimunRateToEatBanana(vector<int> v, int h)
    {
        int maxi = findMax(v);

        for (int i = 1; i <= maxi; i++)
        {
            int reqTime = calculateTotalHrs(v, i);
            if (reqTime <= h)
            {
                return i;
            }
        }
        return maxi;
    }

    int optimal(vector<int> v, int h)
    {
        int low = 1, high = findMax(v);
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int totalH = calculateTotalHrs(v, mid);
            if (totalH <= h)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    Solution sol;
    int ans = sol.optimal(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}