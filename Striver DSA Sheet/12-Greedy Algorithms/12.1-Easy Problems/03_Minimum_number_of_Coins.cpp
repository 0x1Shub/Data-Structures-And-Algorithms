#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void miniCoins(int V, int coins[], int n)
    {
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            while (V >= coins[i])
            {
                V -= coins[i];
                ans.push_back(coins[i]);
            }
        }
        cout << "The minimum number of coins is " << ans.size() << endl;
        cout << "The coins are " << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
    }
};

int main()
{
    int V = 49;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int n = 9;
    Solution sol;
    sol.miniCoins(V, coins, n);
    return 0;
}