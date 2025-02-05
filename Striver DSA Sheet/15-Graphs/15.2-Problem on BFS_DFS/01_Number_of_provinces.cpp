#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void dfs(int node, vector<int> adjLst[], int vis[])
    {
        vis[node] = 1;
        for (auto it : adjLst[node])
        {
            if (!vis[it])
            {
                dfs(it, adjLst, vis);
            }
        }
    }

public:
    int numberOfProvinces(vector<vector<int>> &adj, int V)
    {
        vector<int> adjLst[V];
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjLst[i].push_back(j);
                    adjLst[j].push_back(i);
                }
            }
        }

        int vis[V] = {0};
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, adjLst, vis);
            }
        }
        return count;
    }
};

int main()
{
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    Solution ob;
    cout << ob.numberOfProvinces(adj, 3) << endl;

    return 0;
}