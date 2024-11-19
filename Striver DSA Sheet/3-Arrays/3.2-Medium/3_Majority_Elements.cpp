// Find the Majority Element that occurs more than N/2 times

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityEle(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    count++;
                }
            }
            if (count > n / 2)
            {
                return arr[i];
            }
        }
        return -1;
    }

    // Optimal Approach: Moore’s Voting Algorithm
    int optimal(vector<int> &arr)
    {
        int n = arr.size();
        int count = 0;
        int ele;
        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                ele = arr[i];
            }
            else if (ele == arr[i])
                count++;
            else
                count--;
        }

        int count1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == ele)
                count1++;
        }
        if (count1 > n / 2)
        {
            return ele;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    Solution sol;
    cout << sol.optimal(arr) << endl;
    return 0;
}