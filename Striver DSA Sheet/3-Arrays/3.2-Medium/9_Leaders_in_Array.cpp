#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> printLeader(vector<int> &arr)
    {
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++)
        {
            bool leader = true;
            for (int j = i + 1; j < arr.size(); j++)
            {
                if (arr[j] > arr[i])
                {
                    leader = false;
                    break;
                }
            }
            if (leader == true)
            {
                ans.push_back(arr[i]);
            }
        }
        return ans;
    }

    vector<int> optimal(vector<int> &arr)
    {
        vector<int> ans;
        int n = arr.size();
        int maxi = arr[n - 1];
        ans.push_back(maxi);

        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] > maxi)
            {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    Solution sol;
    vector<int> ans = sol.optimal(arr);
    for (auto it : ans)
    {
        cout << it << endl;
    }
    return 0;
}