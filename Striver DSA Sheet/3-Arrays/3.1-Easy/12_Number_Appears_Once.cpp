// Find the number that appears once, and the other numbers twice

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute-Force Solution
    int getSingleNumber(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == num)
                {
                    count++;
                }
            }
            if (count == 1)
            {
                return num;
            }
        }
        return -1;
    }

    // Using Hasing
    int hashing(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = arr[0];
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        vector<int> hash(maxi + 1, 0);
        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (hash[arr[i]] == 1)
                return arr[i];
        }
        return -1;
    }

    // Using Map
    int getSingleElement(vector<int> &arr)
    {
        int n = arr.size();
        map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }
        for (auto it : mpp)
        {
            if (it.second == 1)
                return it.first;
        }
        return -1;
    }

    // Using XOR
    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        int xorr = 0;
        for (int i = 0; i < n; i++)
        {
            xorr = xorr ^ arr[i];
        }
        return xorr;
    }
};

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    Solution sol;
    cout << sol.hashing(arr) << endl;
    return 0;
}