#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSorted(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution sol;
    cout << sol.isSorted(arr) << endl;
    if (sol.isSorted(arr))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
    return 0;
}