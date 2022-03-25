#include <bits/stdc++.h>

using namespace std;

int V, no_E, graph_type = 0, cycle[50];
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph

int findSet(int i)
{
    while (cycle[i] != i)
    {
        i = cycle[i];
    }
    return i;
}

void unionset(int i, int j)
{
    int a = findSet(i);
    int b = findSet(j);
    cycle[a] = b;
}

void kruskalMST(int adj_matrix[][50])
{
    int mst[V][V];

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            mst[i][j] = 0;
        }
    }

    for (int i = 0; i < V; i++)
    {
        cycle[i] = i;
    }

    int count = 1;
    int min_cost = 0;

    while (count <= V - 1)
    {
        int minimum = INT_MAX;
        int a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj_matrix[i][j] < minimum && findSet(i) != findSet(j))
                {
                    minimum = adj_matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        mst[a][b] = adj_matrix[a][b];
        unionset(a, b);
        min_cost += minimum;
        count++;
        cout << "\nEdge " << a + 1 << " -> " << b + 1 << ", cost: " << minimum;
    }

    cout << endl;
    cout << "The minimum cost of MST is " << min_cost << endl;
}

int main()
{
    int v1, v2, weight, opt;

    cout << "\nWhich type of graph are you entering?\n";
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
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            adj_matrix[i][j] = INT_MAX;
        }
    }

    cout << "\nEnter vertice number between 1 and " << V;
    if (graph_type)
    {
        for (int i = 0; i < no_E; i++)
        {
            cout << "\nEdge " << i + 1 << ":\n";
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
    }
    else
    {
        for (int i = 0; i < no_E; i++)
        {
            cout << "\nEdge " << i + 1 << ":\n";
            cin >> v1 >> v2;
            cout << "Enter weight: ";
            cin >> weight;
            v1--;
            v2--;
            adj_matrix[v1][v2] = weight;
            adj_matrix[v2][v1] = weight;
        }
    }

    kruskalMST(adj_matrix);
    return 0;
}