// Function - Pass by Refrence & Pass by value

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> passBy(int n, int &m)
    {
        return {n + 1, m + 1};
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    Solution sol;
    vector<int> ans = sol.passBy(n, m);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << n << " " << m << endl;

    return 0;
}