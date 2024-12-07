#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findGcd(int n1, int n2)
    {
        int gcd = 1;
        for (int i = 1; i <= min(n1, n2); i++)
        {
            if (n1 % i == 0 && n2 % i == 0)
            {
                gcd = i;
            }
        }
        return gcd;
    }

    int optimal(int n1, int n2)
    {
        while (n1 > 0 && n2 > 0)
        {
            if (n1 > n2)
            {
                n1 = n2 % n1;
            }
            else
            {
                n2 = n2 % n1;
            }
        }
        if (n1 == 0)
        {
            return n2;
        }
        return n1;
    }
};

int main()
{
    int n1 = 9;
    int n2 = 12;
    Solution sol;
    cout << "GCD of two number is: " << sol.optimal(n1, n2) << endl;
    return 0;
}