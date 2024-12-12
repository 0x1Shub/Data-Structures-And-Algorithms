#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &arr)
    {
        int maxLen = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            unordered_set<int> st;
            for (int j = i; j < arr.size(); j++)
            {
                st.insert(arr[j]);
                if (st.size() <= 2)
                {
                    maxLen = max(maxLen, j - i + 1);
                }
                else
                {
                    break;
                }
            }
        }
        return maxLen;
    }

    int optimal(vector<int> &arr)
    {
        int maxLen = 0;
        int l = 0, r = 0;
        unordered_map<int, int> mpp;

        while (r < arr.size())
        {
            mpp[arr[r]]++;
            while (mpp.size() > 2)
            {
                mpp[arr[l]]--;
                if (mpp[arr[l]] == 0)
                {
                    mpp.erase(arr[l]);
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }

        return maxLen;
    }
};

int main()
{
    vector<int> arr = {3, 1, 2, 2, 2, 2};
    Solution sol;
    cout << sol.optimal(arr) << endl;

    return 0;
}