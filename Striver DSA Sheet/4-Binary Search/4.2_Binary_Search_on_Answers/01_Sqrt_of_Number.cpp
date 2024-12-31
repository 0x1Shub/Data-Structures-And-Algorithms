#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sqrt(int num)
    {
        int start = 1;
        int end = num;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            int sq = mid * mid;
            if (sq == num)
            {
                return mid;
            }
            else if (sq > num)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }
};

int main()
{
    int num = 36;
    Solution sol;
    cout << sol.sqrt(num) << endl;
    return 0;
}