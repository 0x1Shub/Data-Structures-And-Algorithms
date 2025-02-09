#include <bits/stdc++.h>

using namespace std;

// Memoization
int f(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = f(n - 1, dp) + f(n - 2, dp);
}

int tabulation(int n)
{
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n] << endl;
    return 0;
}

int spaceOptimization(int n)
{
    int prev2 = 0;
    int prev = 1;

    for (int i = 2; i <= n; i++)
    {
        int cur_i = prev2 + prev;
        prev2 = prev;
        prev = cur_i;
    }

    cout << prev << endl;
    return 0;
}

int main()
{
    int n = 5;
    vector<int> dp(n + 1, -1);

    cout << f(n, dp) << endl;
    tabulation(n);
    spaceOptimization(n);

    return 0;
}
