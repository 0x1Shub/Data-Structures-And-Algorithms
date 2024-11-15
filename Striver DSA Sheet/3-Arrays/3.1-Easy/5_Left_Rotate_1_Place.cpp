#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void leftRotate(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> temp(n);
        for (int i = 1; i < n; i++)
        {
            temp[i - 1] = arr[i];
        }
        temp[n - 1] = arr[0];
        for (auto it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    void optimal(vector<int> &arr)
    {
        int n = arr.size();
        int temp = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
        for (auto it : arr)
        {
            cout << it << " ";
        }
        cout << endl;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    Solution sol;
    sol.optimal(arr);
    return 0;
}