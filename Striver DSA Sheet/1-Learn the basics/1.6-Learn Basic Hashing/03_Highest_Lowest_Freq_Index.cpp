#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void freq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
            map[arr[i]]++;

        int maxFreq = 0, minFreq = n;
        int maxEle = 0, minEle = 0;
        for (auto it : map)
        {
            int count = it.second;
            int element = it.first;

            if (count > maxFreq)
            {
                maxEle = element;
                maxFreq = count;
            }
            if (count < minFreq)
            {
                minEle = element;
                minFreq = count;
            }
        }

        cout << "The highest frequency element is: " << maxEle << "\n";
        cout << "The lowest frequency element is: " << minEle << "\n";
    }
};

int main()
{
    vector<int> arr = {10, 5, 10, 15, 10, 5};
    Solution sol;
    sol.freq(arr);
    return 0;
}