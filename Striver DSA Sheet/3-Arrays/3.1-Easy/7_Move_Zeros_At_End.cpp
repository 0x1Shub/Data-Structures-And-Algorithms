#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> moveZeros(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                temp.push_back(arr[i]);
            }
        }
        int count = n - temp.size();
        for (int i = 0; i < count; i++)
        {
            temp.push_back(0);
        }

        return temp;
    }

    vector<int> optimal(vector<int> &arr)
    {
        int n = arr.size();
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }

        if (j == -1)
            return arr;
        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] != 0)
            {
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return arr;
    }
};

int main()
{
    vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
    Solution sol;
    vector<int> ans = sol.optimal(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}