#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pattern2(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
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
    sol.pattern2(n);
    return 0;
}