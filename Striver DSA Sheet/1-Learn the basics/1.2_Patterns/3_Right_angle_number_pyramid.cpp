#include <bits/stdc++.h>
using namespace std;

class Soltion
{
public:
    void pattern3(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Soltion sol;
    sol.pattern3(n);
    return 0;
}