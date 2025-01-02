#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int finalDays(vector<int> &weights, int cap)
    {
        int days = 1;
        int load = 0;

        for (int i = 0; i < weights.size(); i++)
        {
            if (load + weights[i] > cap)
            {
                days += 1;
                load = weights[i];
            }
            else
            {
                load += weights[i];
            }
        }
        return days;
    }

    int leastWeightCapacity(vector<int> &weights, int d)
    {
        int maxi = *max_element(weights.begin(), weights.end());
        int sum = accumulate(weights.begin(), weights.end(), 0);

        for (int i = maxi; i <= sum; i++)
        {
            if (finalDays(weights, i) <= d)
            {
                return i;
            }
        }
        return -1;
    }

    int optimal(vector<int> &weights, int d)
    {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (finalDays(weights, mid) <= d)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    Solution sol;
    int ans = sol.optimal(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}