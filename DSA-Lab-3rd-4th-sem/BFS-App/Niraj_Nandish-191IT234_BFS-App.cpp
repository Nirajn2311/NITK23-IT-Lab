#include <bits/stdc++.h>

using namespace std;
int V, no_E, graph_type = 0;
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph

vector<int> *inputEdges(vector<int> adj_list[])
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
            adj_list[v1].push_back(v2);
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
            adj_list[v1].push_back(v2);
            adj_list[v2].push_back(v1);
        }
    }

    return adj_list;
}

int BFS(vector<int> adj_list[], int start)
{
    int current_vertex;
    list<int> BFS_queue;
    vector<int> visited;
    vector<int> level(V + 1, -1);

    BFS_queue.push_back(start);
    visited.push_back(start);

    while (!BFS_queue.empty())
    {
        int i = 0;

        current_vertex = BFS_queue.front();
        BFS_queue.pop_front();

        if (level[current_vertex] == -1)
        {
            level[current_vertex] = 0;
        }

        while (i < adj_list[current_vertex].size())
        {
            vector<int>::iterator it = find(visited.begin(), visited.end(), adj_list[current_vertex][i]);

            if (it == visited.end())
            {
                visited.push_back(adj_list[current_vertex][i]);
                BFS_queue.push_back(adj_list[current_vertex][i]);
                if (level[adj_list[current_vertex][i]] == -1)
                {
                    level[adj_list[current_vertex][i]] = level[current_vertex] + 1;
                }
            }

            i++;
        }
    }

    return *max_element(level.begin(), level.end());
}

int main()
{
    int opt;
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

        cout << "\nEnter the number of vertices: ";
        cin >> V;
        cout << "Enter the number of edges: ";
        cin >> no_E;

        vector<int> adj_list[V + 1];
        int diameter = 0;
        int temp;

        inputEdges(adj_list);

        for (int i = 1; i <= V; i++)
        {
            temp = BFS(adj_list, i);
            if (temp > diameter)
            {
                diameter = temp;
            }
        }

        cout << "\nThe diameter of the graph is " << diameter << endl;

        cout << "\nDo you want to try again (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}