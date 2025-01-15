// Minimum number of platforms required for a railway

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPlatform(vector<int> &arr, vector<int> &dep)
    {
        int ans = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            int count = 1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if ((arr[i] >= arr[j] && arr[i] <= dep[j]) || (arr[j] >= arr[i] && arr[j] <= dep[i]))
                {
                    count++;
                }
            }
            ans = max(ans, count);
        }
        return ans;
    }

    int optimal(vector<int> &arr, vector<int> &dep)
    {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int ans = 1;
        int count = 1;
        int i = 1, j = 0;
        while (i < arr.size() && j < dep.size())
        {
            if (arr[i] <= dep[j])
            {
                count++;
                i++;
            }
            else
            {
                count--;
                j++;
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {900, 945, 955, 1100, 1500, 1800};
    vector<int> dep = {920, 1200, 1130, 1150, 1900, 2000};
    Solution sol;
    int ans = sol.countPlatform(arr, dep);
    cout << ans << endl;
    return 0;
}