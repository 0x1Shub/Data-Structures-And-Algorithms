#include <bits/stdc++.h>
using namespace std;

// Swap Index of element not the element completely it will provide wrong output

class Solution
{
public:
    void selectionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int mini = i;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] < arr[mini])
                {
                    mini = j;
                }
            }
            swap(arr[i], arr[mini]);
        }
    }
};

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    Solution sol;
    sol.selectionSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}