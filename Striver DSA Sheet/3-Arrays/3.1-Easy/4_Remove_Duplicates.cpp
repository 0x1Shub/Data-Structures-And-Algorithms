// Remove Duplicates in-place from Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    set<int> removeDuplicates(vector<int> &arr)
    {
        int n = arr.size();
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(arr[i]);
        }
        return st;
    }

    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        int i = 0;
        for (int j = 1; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                i++;
                arr[i] = arr[j];
            }
        }
        return i + 1;
    }
};

int main()
{
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    Solution sol;
    set<int> ans = sol.removeDuplicates(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    // Size of array
    cout << sol.optimal(arr) << endl;
    return 0;
}