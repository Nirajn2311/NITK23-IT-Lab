#include <bits/stdc++.h>

using namespace std;
int V, no_E, graph_type, count;
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph
// count: Counter variable to make sure graph is connected or not

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

void BFS(int node, vector<bool> visited, vector<vector<int>> adj_list)
{
    int n;
    vector<int> bfs_queue;
    visited[node] = true;
    bfs_queue.push_back(node);
    while (!bfs_queue.empty())
    {
        n = bfs_queue.front();
        cout << n + 1 << " ";
        ::count++;
        bfs_queue.erase(bfs_queue.begin());

        for (vector<int>::iterator i = adj_list[n].begin(); i != adj_list[n].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                bfs_queue.push_back(*i);
            }
        }
    }
}

vector<bool> DFS(int node, vector<bool> visited, vector<vector<int>> adj_list)
{
    visited[node] = true;
    cout << node + 1 << " ";
    ::count++;
    for (vector<int>::iterator i = adj_list[node].begin(); i != adj_list[node].end(); i++)
    {
        if (!visited[*i])
        {
            visited = DFS(*i, visited, adj_list);
        }
    }
    return visited;
}

int main()
{
    int opt, node;
    char ans;
    do
    {
        cout << "\n\nWhich graph do you want adjacency matrix and list for?\n";
        cout << "1. Directed graph\n";
        cout << "2. Undirected graph\n";
        cout << "Enter your option: ";
        cin >> opt;
        if (opt != 1 && opt != 2)
        {
            cout << "\n\nINVALID OPTION ENTERED!!!\n";
            exit(1);
        }
        graph_type = opt % 2;

        cout << "\nEnter number of vertices: ";
        cin >> V;
        cout << "Enter number of edges: ";
        cin >> no_E;

        vector<vector<int>> E;
        vector<bool> visited(V, false);
        vector<vector<int>> adj_list(V, vector<int>());

        E = inputEdges(E);
        adj_list = adjacencyList(adj_list, E);

        cout << "\nEnter node to start BFS and DFS from: ";
        cin >> node;
        node--;

        ::count = 0;
        cout << "BFS: ";
        BFS(node, visited, adj_list);
        if (::count != V)
        {
            cout << "\rDISCONNECTED GRAPH\n";
            goto end;
        }

        ::count = 0;
        cout << "\nDFS: ";
        visited = DFS(node, visited, adj_list);
        if (::count != V)
        {
            cout << "\rDISCONNECTED GRAPH\n";
            goto end;
        }
        cout << endl;

    end:
        cout << "\nDo you want to try again (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
