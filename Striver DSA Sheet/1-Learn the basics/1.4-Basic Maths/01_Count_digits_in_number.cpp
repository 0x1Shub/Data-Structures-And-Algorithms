#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDigits(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += 1;
            n = n / 10;
        }
        return count;
    }

    int optimal(int n)
    {
        int count = (int)(log10(n) + 1);
        return count;
    }
};

int main()
{
    int n = 329823;
    Solution sol;
    cout << "Count digits: " << sol.optimal(n) << endl;
    return 0;
}