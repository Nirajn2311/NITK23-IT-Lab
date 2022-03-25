#include <bits/stdc++.h>

using namespace std;
int V, no_E, graph_type = 0;
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph

int diameter[10001];
//

vector<vector<int>> inputEdges(vector<vector<int>> E)
{
    cout << "\nEnter vertice number between 1 and " << V;
    for (int i = 0; i < no_E; i++)
    {
        int v1, v2;
        if (graph_type)
        {
        tailDirectedEdges:
            cout << "\nEdge " << i + 1 << ":\n";
            cout << "Tail Vertex: ";
            cin >> v1;
            if (v1 > V || v1 == 0)
            {
                cout << "\nERROR: Incorrect vertice entered. Enter value again\n";
                goto tailDirectedEdges;
            }
        headDirectedEdges:
            cout << "Head Vertex: ";
            cin >> v2;
            if (v2 > V || v2 == 0)
            {
                cout << "\nERROR: Incorrect vertice entered. Enter value again\n";
                goto headDirectedEdges;
            }
        }
        else
        {
        edges:
            cout << "\nEdge " << i + 1 << ":\n";
            cin >> v1 >> v2;
            if (v1 > V || v2 > V || v1 == 0 || v2 == 0)
            {
                cout << "\nERROR: Incorrect vertice entered. Enter values again\n";
                goto edges;
            }
        }
        E.push_back(vector<int>());
        E[i].push_back(v1);
        E[i].push_back(v2);
    }

    return E;
}

vector<vector<int>> adjacencyList(vector<vector<int>> adj_list, vector<vector<int>> E)
{
    for (int i = 0; i < no_E; i++)
    {
        if (E[i][0] != E[i][1])
        {
            int flag = 0;
            for (int j = 0; j < adj_list[E[i][0] - 1].size(); j++)
            {
                if (adj_list[E[i][0] - 1][j] == (E[i][1] - 1))
                {
                    flag = 1;
                }
            }
            if (!flag)
            {
                adj_list[E[i][0] - 1].push_back(E[i][1] - 1);
                if (!graph_type)
                {
                    adj_list[E[i][1] - 1].push_back(E[i][0] - 1);
                }
            }
        }
    }

    return adj_list;
}

int BFS(int node, vector<bool> visited, vector<vector<int>> adj_list)
{
    vector<int> bfs_queue;
    bfs_queue.push_back(node);
    visited[node] = true;
    while (!bfs_queue.empty())
    {
        int n = bfs_queue.front();
        bfs_queue.erase(bfs_queue.begin());

        for (vector<int>::iterator i = adj_list[n].begin(); i != adj_list[n].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                diameter[*i] += diameter[n] + 1;
                bfs_queue.push_back(*i);
            }
        }
    }
    cout << endl;
    for (int i = 0; i < V; i++)
    {
        cout << diameter[i] << endl;
    }
    cout << endl;

    return int(max_element(diameter, diameter + V) - diameter);
}

int findDia(vector<vector<int>> adj_list, vector<bool> visited)
{
    int initial_node = BFS(0, visited, adj_list);
    int final_node = BFS(initial_node, visited, adj_list);
    cout << initial_node << final_node;
    return diameter[final_node];
}

int main()
{
    int opt;
    cout << "\nEnter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> no_E;

    vector<vector<int>> E;
    vector<bool> visited(V, false);
    vector<vector<int>> adj_list(V, vector<int>());

    E = inputEdges(E);
    adj_list = adjacencyList(adj_list, E);
    dia = findDia(adj_list, visited);

    cout << dia << endl;

    return 0;
}
