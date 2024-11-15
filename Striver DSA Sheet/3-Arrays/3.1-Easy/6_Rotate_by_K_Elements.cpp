#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void Rotatetoright(vector<int> &arr, int n, int k)
    {
        if (n == 0)
            return;
        k = k % n;
        if (k > n)
            return;
        int temp[k];
        for (int i = n - k; i < n; i++)
        {
            temp[i - n + k] = arr[i];
        }
        for (int i = n - k - 1; i >= 0; i--)
        {
            arr[i + k] = arr[i];
        }
        for (int i = 0; i < k; i++)
        {
            arr[i] = temp[i];
        }
    }

    void Rotatetoleft(vector<int> &arr, int n, int k)
    {
        if (n == 0)
            return;
        k = k % n;
        if (k > n)
            return;
        int temp[k];
        for (int i = 0; i < k; i++)
        {
            temp[i] = arr[i];
        }
        for (int i = 0; i < n - k; i++)
        {
            arr[i] = arr[i + k];
        }
        for (int i = n - k; i < n; i++)
        {
            arr[i] = temp[i - n + k];
        }
    }
};

class ReversalAlgorithm
{
public:
    void Reverse(vector<int> &arr, int start, int end)
    {
        while (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }

    void Rotateeletoright(vector<int> &arr, int n, int k)
    {
        Reverse(arr, 0, n - k - 1);
        Reverse(arr, n - k, n - 1);
        Reverse(arr, 0, n - 1);
    }

    void Rotateeletoleft(vector<int> &arr, int n, int k)
    {
        Reverse(arr, 0, k - 1);
        Reverse(arr, k, n - 1);
        Reverse(arr, 0, n - 1);
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int k = 2;

    ReversalAlgorithm ans;
    ans.Rotateeletoleft(arr, n, k);
    return 0;
}