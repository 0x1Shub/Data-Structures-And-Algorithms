#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void generate(int k, char str[], int n)
    {
        if (n == k)
        {
            str[n] = '\0';
            cout << str << " ";
            return;
        }

        else if (str[n - 1] == '1')
        {
            str[n] = '0';
            generate(k, str, n + 1);
        }

        else if (str[n - 1] == '0')
        {
            str[n] = '0';
            generate(k, str, n + 1);
            str[n] = '1';
            generate(k, str, n + 1);
        }
    }

    void generateAllStrings(int k)
    {
        if (k <= 0)
            return;
        char str[k + 1];

        str[0] = '0';
        generate(k, str, 1);

        str[0] = '1';
        generate(k, str, 1);
    }
};

int main()
{
    int K = 3;
    Solution sol;
    sol.generateAllStrings(K);
    return 0;
}