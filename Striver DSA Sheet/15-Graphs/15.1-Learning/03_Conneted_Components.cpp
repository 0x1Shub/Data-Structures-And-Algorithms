#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<int> *adj;

    void DFSUtil(int v, bool visited[], vector<int> &component);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void connectedComponents();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFSUtil(int v, bool visited[], vector<int> &component)
{
    visited[v] = true;
    component.push_back(v);
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            DFSUtil(i, visited, component);
        }
    }
}

void Graph::connectedComponents()
{
    bool *visited = new bool[V];
    for (int v = 0; v < V; v++)
    {
        visited[v] = false;
    }
    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false)
        {
            vector<int> component;
            DFSUtil(v, visited, component);
            cout << "Connected Component: ";
            for (int i : component)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    delete[] visited;
}

int main()
{
    Graph g(5);

    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "Following are connected components \n";
    g.connectedComponents();

    return 0;
}
