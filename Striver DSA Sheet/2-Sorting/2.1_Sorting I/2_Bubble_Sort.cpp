#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void bubbleSort(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
};

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};
    Solution sol;
    sol.bubbleSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}