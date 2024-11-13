#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j > 0 && arr[j - 1] > arr[j])
            {
                swap(arr[j - 1], arr[j]);
                j--;
            }
        }
    }
};

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    Solution sol;
    sol.insertionSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}