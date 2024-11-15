// Find the missing number in an array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Using Linear Search
    int number(vector<int> &a, int N)
    {
        for (int i = 1; i <= N; i++)
        {
            int flag = 0;
            for (int j = 0; j < N - 1; j++)
            {
                if (a[j] == i)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                return i;
        }
        return -1;
    }

    // Using Hashing
    int missingNumber(vector<int> &arr, int N)
    {
        int hash[N + 1] = {0};
        for (int i = 0; i < N - 1; i++)
            hash[arr[i]]++;
        for (int i = 1; i <= N; i++)
        {
            if (hash[i] == 0)
            {
                return i;
            }
        }
        return -1;
    }

    // Optimal -> Using Summation
    int Optimal1(vector<int> &arr, int n)
    {
        int sum = (n * (n + 1)) / 2;
        int sum2 = 0;
        for (int i = 0; i < n; i++)
        {
            sum2 += arr[i];
        }
        int missingNumber = sum - sum2;
        return missingNumber;
    }

    // Optimal -> Using XOR
    int Optimal2(vector<int> &arr, int n)
    {
        int xor1 = 0, xor2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            xor2 = xor2 ^ arr[i];
            xor1 = xor1 ^ (i + 1);
        }
        xor1 = xor1 ^ n;
        return (xor1 ^ xor2);
    }
};

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    int n = arr.size();
    Solution sol;
    cout << sol.Optimal2(arr, n) << endl;
    return 0;
}