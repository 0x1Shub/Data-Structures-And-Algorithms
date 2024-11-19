// Sort an array of 0s, 1s and 2s

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute-force approach : Using three variables
    void sortArr(vector<int> &arr)
    {
        int n = arr.size();
        int count1 = 0;
        int count2 = 0;
        int count0 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
                count0++;
            else if (arr[i] == 1)
                count1++;
            else
                count2++;
        }

        for (int i = 0; i < count0; i++)
        {
            arr[i] = 0;
        }

        for (int i = count0; i < count0 + count1; i++)
        {
            arr[i] = 1;
        }

        for (int i = count0 + count1; i < n; i++)
        {
            arr[i] = 2;
        }
    }

    // Optimal: Dutch National flag algorithm.
    void optimal(vector<int> &arr)
    {
        int n = arr.size();
        int low = 0, mid = 0;
        int high = n - 1;
        while (mid <= high)
        {
            if (arr[mid] == 0)
            {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if (arr[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(arr[high], arr[mid]);
                high--;
            }
        }
    }
};

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    Solution sol;
    sol.optimal(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}