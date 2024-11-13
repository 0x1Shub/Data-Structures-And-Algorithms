#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr, int n)
    {
        if (n == 1)
            return;
        for (int j = 0; j <= n - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }

        bubbleSort(arr, n - 1);
    }
};

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();
    Solution sol;
    sol.bubbleSort(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}