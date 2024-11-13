#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void insertionSort(vector<int> &arr, int i, int n)
    {
        if (i == n)
        {
            return;
        }
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j], arr[j - 1]);
            j--;
        }

        insertionSort(arr, i + 1, n);
    }
};

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    int n = arr.size();
    Solution sol;
    sol.insertionSort(arr, 0, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}