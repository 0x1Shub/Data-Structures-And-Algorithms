#include <bits/stdc++.h>
using namespace std;

// Adjacency Matrix

int adjacencyMatrix()
{
    int n, m;
    cin >> n >> m;

    int adj[n + 1][n + 1];
    // Initialize the adjacency matrix with zeros
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            adj[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Print the adjacency matrix
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Adjacency List

int adjacencyList()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Print the adjacency list
    for (int i = 1; i <= n; i++)
    {
        cout << "Adjacency list of vertex " << i << ": ";
        for (int j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}

// Main function to test the above implementations
int main()
{
    // Uncomment to test adjacency matrix
    adjacencyMatrix();

    // Uncomment to test adjacency list
    // adjacencyList();

    return 0;
}