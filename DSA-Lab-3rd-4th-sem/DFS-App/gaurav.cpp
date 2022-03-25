#include <bits/stdc++.h>
using namespace std;
#define NIL 0;
class Edge
{
public:
    int first;
    int second;
};
vector<Edge> result;

void dfs(vector<int> adj[], int start, int v, int time, int parent[], vector<bool> visited, int low[], int discovered_time[])
{
    visited[start] = true;
    discovered_time[start] = time + 1;
    low[start] = time + 1;
    time++;
    int i = 0;
    while (i < adj[start].size())
    {
        if (!visited[adj[start][i]])
        {
            parent[adj[start][i]] = start;
            dfs(adj, adj[start][i], v, time, parent, visited, low, discovered_time);
            low[start] = min(low[start], low[adj[start][i]]);
            if (low[adj[start][i]] > discovered_time[start])
            {
                result.push_back({start, adj[start][i]});
            }
        }
        else if (parent[start] != adj[start][i])
        {
            low[start] = min(low[start], discovered_time[adj[start][i]]);
        }
        i++;
    }
}

int main()
{
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    vector<int> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cout << "Enter the vertices of any edge: " << endl;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout << "The graph is: " << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << i << "\t";
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    vector<bool> visited(v + 1, false);
    int discovered_time[v + 1];
    int low[v + 1];
    int time = 0;
    int parent[v + 1];
    parent[1] = NIL;

    dfs(adj, 1, v, time, parent, visited, low, discovered_time);
    if (result.size() == 0)
    {
        cout << "This graph is 2 edge connected" << endl;
    }
    else
    {
        cout << "The graph is not 2 edge connected" << endl;
        cout << "The Bridges in the graph are: " << endl;

        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i].first << " " << result[i].second << endl;
        }
    }
}