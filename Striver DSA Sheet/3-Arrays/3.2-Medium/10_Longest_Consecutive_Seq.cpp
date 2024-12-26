#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool linearSearch(vector<int> &arr, int target)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == target)
            {
                return true;
            }
        }
        return false;
    }

    int logestSuccesiveEle(vector<int> &arr)
    {
        int n = arr.size();
        int longest = -1;

        for (int i = 0; i < n; i++)
        {
            int x = arr[i];
            int count = 1;

            while (linearSearch(arr, x + 1) == true)
            {
                x += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
        return longest;
    }

    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;
        int longest = 1;
        unordered_set<int> st;

        for (int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end())
            {
                int count = 1;
                int x = it;
                while (st.find(x + 1) != st.end())
                {
                    x = x + 1;
                    count = count + 1;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> arr = {100, 200, 1, 3, 2, 4};
    Solution sol;
    cout << sol.optimal(arr) << endl;
    return 0;
}