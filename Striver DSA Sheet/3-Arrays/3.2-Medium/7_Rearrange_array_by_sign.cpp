#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrageBySign(vector<int> &arr)
    {
        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > 0)
            {
                pos.push_back(arr[i]);
            }
            else
            {
                neg.push_back(arr[i]);
            }
        }

        for (int i = 0; i < arr.size() / 2; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        return arr;
    }

    vector<int> optimal(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, 0);

        int posIndex = 0, negIndex = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                ans[negIndex] = arr[i];
                negIndex += 2;
            }
            else
            {
                ans[posIndex] = arr[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 2, -4, -5};
    Solution sol;
    vector<int> ans = sol.optimal(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}