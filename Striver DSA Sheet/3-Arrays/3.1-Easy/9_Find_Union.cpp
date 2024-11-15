#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 1. Using Map
    vector<int> findUnion(vector<int> &arr1, vector<int> &arr2, int n, int m)
    {
        map<int, int> mpp;
        vector<int> Union;
        for (int i = 0; i < n; i++)
        {
            mpp[arr1[i]]++;
        }
        for (int i = 0; i < m; i++)
        {
            mpp[arr2[i]]++;
        }

        for (auto &it : mpp)
        {
            Union.push_back(it.first);
        }
        return Union;
    }

    // 2. Using Set
    vector<int> brute(vector<int> &arr1, vector<int> &arr2, int n, int m)
    {
        set<int> st;
        vector<int> Union;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr1[i]);
        }
        for (int i = 0; i < m; i++)
        {
            st.insert(arr2[i]);
        }

        for (auto &it : st)
        {
            Union.push_back(it);
        }

        return Union;
    }

    // 3. Using two pointer
    vector<int> optimal(vector<int> &arr1, vector<int> &arr2, int n, int m)
    {
        int i = 0, j = 0;
        vector<int> Union;
        while (i < n && j < m)
        {
            if (arr1[i] <= arr2[j])
            {
                if (Union.size() == 0 || Union.back() != arr1[i])
                {
                    Union.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if (Union.size() == 0 || Union.back() != arr2[j])
                {
                    Union.push_back(arr2[j]);
                }
                j++;
            }
        }
        while (i < n)
        {
            if (Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        while (j < m)
        {
            if (Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
        return Union;
    }
};

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    int n = arr1.size();
    int m = arr2.size();

    Solution sol;
    vector<int> ans = sol.optimal(arr1, arr2, n, m);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}