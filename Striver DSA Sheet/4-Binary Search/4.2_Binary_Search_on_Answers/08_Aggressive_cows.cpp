#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canWePlace(vector<int> &stalls, int dist, int cows)
    {
        int n = stalls.size();
        int cntCows = 1;
        int last = stalls[0];
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - last >= dist)
            {
                cntCows++;
                last = stalls[i];
            }
            if (cntCows >= cows)
                return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());

        int limit = stalls[n - 1] - stalls[0];
        for (int i = 1; i <= limit; i++)
        {
            if (canWePlace(stalls, i, k) == false)
            {
                return (i - 1);
            }
        }
        return limit;
    }

    int optimal(vector<int> &stalls, int k)
    {
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int low = 1, high = stalls[n - 1] - stalls[0];
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (canWePlace(stalls, mid, k) == true)
            {
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    Solution sol;
    int ans = sol.optimal(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}