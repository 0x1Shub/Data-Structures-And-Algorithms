#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int palindromeNum(int n)
    {
        int reverse = 0;
        while (n > 0)
        {
            int rem = n % 10;
            reverse = reverse * 10 + rem;
            n = n / 10;
        }
        return reverse;
    }
};

int main()
{
    int n = 12321;
    Solution sol;
    if (sol.palindromeNum(n) == n)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }
    return 0;
}