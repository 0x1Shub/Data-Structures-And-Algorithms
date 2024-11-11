#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void pattern7(int N)
    {
        // This is the outer loop which will loop for the rows.
        for (int i = 0; i < N; i++)
        {
            // For printing the spaces before stars in each row
            for (int j = 0; j < N - i - 1; j++)
            {
                cout << " ";
            }

            // For printing the stars in each row
            for (int j = 0; j < 2 * i + 1; j++)
            {

                cout << "*";
            }

            // For printing the spaces after the stars in each row
            for (int j = 0; j < N - i - 1; j++)
            {
                cout << " ";
            }

            // As soon as the stars for each iteration are printed, we move to the
            // next row and give a line break otherwise all stars
            // would get printed in 1 line.
            cout << endl;
        }
    }
};

int main()
{
    int n = 5;
    Solution sol;
    sol.pattern7(n);
    return 0;
}