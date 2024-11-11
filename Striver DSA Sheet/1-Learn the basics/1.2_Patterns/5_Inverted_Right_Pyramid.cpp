#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pattern5(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = n; j >= i; j--)
            {
                cout << "* ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    sol.pattern5(n);
    return 0;
}