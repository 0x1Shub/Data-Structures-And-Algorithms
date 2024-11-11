#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pyramid(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < 2 * i + 1; j++)
            {
                cout << "*";
            }

            for (int j = 0; j < n - i - 1; j++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }

    void invertedPyramid(int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }

            for (int j = 0; j < 2 * n - (2 * i + 1); j++)
            {
                cout << "*";
            }

            for (int i = 0; i < n; i++)
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
    sol.pyramid(n);
    sol.invertedPyramid(n);

    return 0;
}