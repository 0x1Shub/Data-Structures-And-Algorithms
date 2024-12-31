#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int func(int mid, int num, int n)
    {
        int ans = 1;
        for (int i = 1; i <= n; i++)
        {
            ans = ans * mid;
            if (ans > num)
            {
                return 2;
            }
        }
        if (ans == num)
        {
            return 1;
        }
        return 0;
    }

    int NthRoot(int num, int n)
    {
        int start = 1;
        int end = num;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            int midN = func(mid, num, n);
            if (midN == 1)
            {
                return mid;
            }
            else if (midN == 0)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return -1;
    }
};

int main()
{
    int num = 27;
    int n = 3;
    Solution sol;
    cout << sol.NthRoot(num, n) << endl;
    return 0;
}