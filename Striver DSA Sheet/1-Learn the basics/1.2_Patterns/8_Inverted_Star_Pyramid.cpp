#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pattern8(int n)
    {
        for (int i = 0; i < n; i++)
        {
            // space
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            // star
            for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            {
                cout << "*";
            }

            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n = 5;
    Solution sol;
    sol.pattern8(n);
    return 0;
}