#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverseNum(int n)
    {
        int ans = 0;
        while (n > 0)
        {
            int rem = n % 10;
            ans = ans * 10 + rem;
            n = n / 10;
        }
        return ans;
    }
};

int main()
{
    int n = 12345;
    Solution sol;
    cout << "Reverse number is: " << sol.reverseNum(n) << endl;
    return 0;
}