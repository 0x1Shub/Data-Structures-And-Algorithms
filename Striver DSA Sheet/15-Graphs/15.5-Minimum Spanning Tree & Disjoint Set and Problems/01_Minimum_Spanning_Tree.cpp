#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<pair<int, int>> adj[]) {
        vector<int> vis(V, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int sum = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();
            
            if (vis[node] == 1) continue;
            
            vis[node] = 1;
            
            sum += wt;
            
            for (auto it : adj[node]) {
                int cnode = it.first;
                int cost = it.second;
                if (!vis[cnode]) {
                    pq.push({cost, cnode});
                }
            }
        }
        return sum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
