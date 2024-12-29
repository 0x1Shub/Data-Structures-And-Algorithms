// Count the number of subarrays with given xor K

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorr(vector<int> &arr, int k)
    {
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i; j < arr.size(); j++)
            {
                int xorr = 0;
                for (int k = i; k <= j; k++)
                {
                    xorr = xorr ^ arr[k];
                }
                if (xorr == k)
                {
                    count++;
                }
            }
        }
        return count;
    }

    int optimal(vector<int> &arr, int k)
    {
        int xorr = 0;
        map<int, int> mpp;
        mpp[xorr]++;
        int count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            xorr = xorr ^ arr[i];
            int x = xorr ^ k;
            count += mpp[x];
            mpp[xorr]++;
        }
        return count;
    }
};

int main()
{
    vector<int> arr = {5, 6, 7, 8, 9};
    int k = 5;
    Solution sol;
    cout << sol.optimal(arr, k) << endl;
    return 0;
}