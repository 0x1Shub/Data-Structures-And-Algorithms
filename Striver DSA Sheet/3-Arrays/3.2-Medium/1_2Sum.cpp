// Two Sum : Check if a pair with given sum exists in Array

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] + arr[j] == target)
                {
                    return true;
                }
            }
        }
        return false;
    }

    // Better Approach : Using Hashing
    vector<int> hashing(vector<int> &arr, int target)
    {
        int n = arr.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end())
            {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return {-1, -1};
    }

    // Optimal Approach : Two Pointer
    bool optimal(vector<int> &arr, int target)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = left + right;
            if (sum == target)
            {
                return true;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main()
{
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    Solution sol;
    if (sol.twoSum(arr, target))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}