#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pattern6(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= i; j--)
            {
                cout << n - j + 1 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 5;
    Solution sol;
    sol.pattern6(n);
    return 0;
}