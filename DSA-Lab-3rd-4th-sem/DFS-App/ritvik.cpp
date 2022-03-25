#include <bits/stdc++.h>
using namespace std;

void insert_edge(vector<int> adj_list[], int start, int destination)
{
    adj_list[start].push_back(destination);
}

int dfs(vector<int> adj_list[], vector<bool> visited, int arrival_time[], int vertex, int parent, int &time)
{
    visited[vertex] = true;
    arrival_time[vertex] = time++;
    int deepest_BE = arrival_time[vertex];
    for (vector<int>::iterator i = adj_list[vertex].begin(); i != adj_list[vertex].end(); i++)
    {
        if (visited[*i] == false)
        {
            deepest_BE = min(deepest_BE, dfs(adj_list, visited, arrival_time, *i, vertex, time));
        }
        else if (*i != parent)
        {
            deepest_BE = min(deepest_BE, arrival_time[*i]);
        }
    }
    if (deepest_BE == arrival_time[vertex] && parent != -1)
        cout << "The bridge edge is " << parent << "->" << vertex << endl;
    return deepest_BE;
}

int main()
{
    int vertices;
    int edges;
    int i, start, destination, node;
    int parent = -1, time = 0, arrival_time[50];
    vector<bool> visited(vertices, false);
    vector<int> adj_list[50];
    cout << "Enter number of edges and vertices of the graph : ";
    cin >> edges >> vertices;
    for (i = 1; i <= edges; i++)
    {
        cout << "Enter the extremes of " << i << " edge : ";
        cin >> start >> destination;
        insert_edge(adj_list, start, destination);
        insert_edge(adj_list, destination, start);
    }
    int vertex = 0;
    dfs(adj_list, visited, arrival_time, vertex, parent, time);
    return 0;
}