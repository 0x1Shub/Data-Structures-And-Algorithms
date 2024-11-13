#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void mergeSort(vector<int> &arr, int low, int high)
    {
        if (low >= high)
            return;
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] < arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }
};

int main()
{
    vector<int> arr = {3, 2, 8, 5, 1, 4, 23};
    int low = 0;
    int high = arr.size() - 1;
    Solution sol;
    sol.mergeSort(arr, low, high);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}