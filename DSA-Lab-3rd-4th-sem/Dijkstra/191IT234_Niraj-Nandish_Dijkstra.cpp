#include <bits/stdc++.h>

using namespace std;
int V, no_E, graph_type = 0, startNode = 1;
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph
// startNode: Start Dijkstra at Vertex 1

void dijkstra(int adj_mat[][50], int start, int dest)
{
    int visited[V], path[V], distance[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }

    distance[start] = 0;

    for (int count = 0; count < V; count++)
    {
        int min = INT_MAX;
        int pos = 0;

        for (int i = 0; i < V; i++)
        {
            if (visited[i] == 0)
            {
                if (distance[i] < min)
                {
                    min = distance[i];
                    pos = i;
                }
            }
        }

        visited[pos] = 1;

        for (int j = 0; j < V; j++)
        {
            if (adj_mat[pos][j] && visited[j] == 0 && (distance[pos] + adj_mat[pos][j]) < distance[j])
            {
                distance[j] = distance[pos] + adj_mat[pos][j];
                path[j] = pos;
            }
        }
    }

    cout << "\nShortest distance from " << start + 1 << " to " << dest + 1 << ": " << distance[dest] << endl;

    int tempArr[V];
    int x = 0, t = dest;
    tempArr[0] = dest;
    x++;

    do
    {
        tempArr[x] = path[t];
        t = path[t];
        x++;
    } while (t != start);

    cout << "Shortest path from " << start + 1 << " to " << dest + 1 << ": ";
    cout << start + 1;

    for (int z = x - 2; z >= 0; z--)
    {
        cout << " -> ";
        cout << tempArr[z] + 1;
    }

    cout << endl;
}

void dijkstraToAll(int adj_mat[][50], int start)
{
    cout << "\n----------------------------------------------\n";
    for (int i = 0; i < V; i++)
    {
        if (i != start)
        {
            dijkstra(adj_mat, start, i);
            cout << endl;
        }
    }
}

int main()
{
    int opt;
    int v1, v2, weight;
    int i;

    cout << "\nWhich graph do you want adjacency matrix and list for?\n";
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

    int adj_matrix[50][50];
    for (i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj_matrix[i][j] = 0;
        }
    }

    cout << "\nEnter vertice number between 1 and " << V;
    switch (graph_type)
    {
    case 1:
        for (i = 1; i <= no_E; i++)
        {
            cout << "\nEdge " << i << ":\n";
            cout << "Tail Vertex: ";
            cin >> v1;
            cout << "Head Vertex: ";
            cin >> v2;
            cout << "Enter weight: ";
            cin >> weight;
            v1--;
            v2--;
            adj_matrix[v1][v2] = weight;
        }

        dijkstraToAll(adj_matrix, startNode - 1);
        break;

    case 2:
        for (i = 1; i <= no_E; i++)
        {
            cout << "\nEdge " << i << ":\n";
            cin >> v1 >> v2;
            cout << "Enter weight: ";
            cin >> weight;
            v1--;
            v2--;
            adj_matrix[v1][v2] = weight;
            adj_matrix[v2][v1] = weight;
        }

        dijkstraToAll(adj_matrix, startNode - 1);
        break;

    default:
        cout << "Invalid Option ";
    }
}