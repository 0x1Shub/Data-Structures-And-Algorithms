#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void frequ(vector<int> &arr)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        for (auto it : mpp)
        {
            cout << it.first << " -> " << it.second << endl;
        }
    }
};

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    Solution sol;
    sol.frequ(arr);
    return 0;
}