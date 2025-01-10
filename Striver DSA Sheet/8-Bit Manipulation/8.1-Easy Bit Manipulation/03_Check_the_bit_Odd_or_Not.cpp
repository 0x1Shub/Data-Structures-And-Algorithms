#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEven(int n)
    {
        if (n & 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    int n = 12;
    Solution sol;
    if (sol.isEven(n))
    {
        cout << "Even" << endl;
    }
    else
    {
        cout << "Odd" << endl;
    }
    return 0;
}