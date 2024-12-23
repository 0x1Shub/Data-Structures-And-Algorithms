#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> next_permutation(vector<int> &arr)
    {
        int n = arr.size();
        std::next_permutation(arr.begin(), arr.end());
        return arr;
    }

    vector<int> optimal(vector<int> &arr)
    {
        int n = arr.size();

        int ind = -1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                ind = i;
                break;
            }
        }

        if (ind = -1)
        {
            reverse(arr.begin(), arr.end());
            return arr;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > arr[ind])
            {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        reverse(arr.begin() + ind + 1, arr.end());
        return arr;
    }
};

int main()
{

    vector<int> arr = {1, 3, 2};
    Solution sol;
    vector<int> ans = sol.optimal(arr);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}