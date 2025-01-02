#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divisor(vector<int> &arr, int threshold)
    {
        int maxi = *max_element(arr.begin(), arr.end());

        for (int i = 1; i <= maxi; i++)
        {
            int sum = 0;
            for (int j = 0; j < arr.size(); j++)
            {
                sum += ceil((double)(arr[j]) / (double)(i));
            }
            if (sum <= threshold)
            {
                return i;
            }
        }
        return -1;
    }

    int sumByD(vector<int> &arr, int mid)
    {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            sum += ceil((double)(arr[i]) / (double)(mid));
        }
        return sum;
    }

    int optimal(vector<int> &arr, int threshold)
    {
        int start = 1;
        int end = *max_element(arr.begin(), arr.end());
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (sumByD(arr, mid) <= threshold)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return start;
    }
};

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int threshold = 6;
    Solution sol;
    cout << sol.optimal(arr, threshold) << endl;
    return 0;
}