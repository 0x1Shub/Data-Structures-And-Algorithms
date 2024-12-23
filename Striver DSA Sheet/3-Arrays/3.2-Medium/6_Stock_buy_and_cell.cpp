#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPro(vector<int> &arr)
    {
        int maxPro = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxPro = max(arr[j] - arr[i], maxPro);
            }
        }
        return maxPro;
    }

    int optimal(vector<int> &arr)
    {
        int maxPro = 0;
        int miniPrice = INT_MAX;

        for (int i = 0; i < arr.size(); i++)
        {
            miniPrice = min(miniPrice, arr[i]);
            maxPro = max(arr[i] - miniPrice, maxPro);
        }

        return maxPro;
    }
};

int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    Solution sol;
    cout << sol.optimal(arr) << endl;
    return 0;
}