#include <bits/stdc++.h>

using namespace std;
int V, no_E;

vector<vector<int>> undirectedInputEdges(vector<vector<int>> E)
{
    for (int i = 0; i < no_E; i++)
    {
    edges:
        int v1, v2;
        cout << "\nEdge " << i + 1 << ":\n";
        cin >> v1 >> v2;
        if (v1 > V || v2 > V || v1 == 0 || v2 == 0)
        {
            cout << "\nERROR: Incorrect vertice entered. Enter values again\n";
            goto edges;
        }
        E.push_back(vector<int>());
        E[i].push_back(v1);
        E[i].push_back(v2);
    }

    return E;
}

vector<vector<int>> undirectedAdjacencyMatrix(vector<vector<int>> adj_mat, vector<vector<int>> E)
{
    for (int i = 0; i < V; i++)
    {
        adj_mat.push_back(vector<int>());
        for (int j = 0; j < V; j++)
        {
            adj_mat[i].push_back(0);
        }
    }

    for (int i = 0; i < no_E; i++)
    {
        if (E[i][0] != E[i][1])
        {
            if (adj_mat[E[i][0] - 1][E[i][1] - 1])
            {
                adj_mat[E[i][0] - 1][E[i][1] - 1] += 1;
                adj_mat[E[i][1] - 1][E[i][0] - 1] += 1;
            }
            else
            {
                adj_mat[E[i][0] - 1][E[i][1] - 1] = 1;
                adj_mat[E[i][1] - 1][E[i][0] - 1] = 1;
            }
        }
        else
        {
            if (adj_mat[E[i][0] - 1][E[i][0] - 1])
            {
                adj_mat[E[i][0] - 1][E[i][0] - 1] += 1;
            }
            else
            {
                adj_mat[E[i][0] - 1][E[i][0] - 1] = 1;
            }
        }
    }

    return adj_mat;
}

vector<vector<int>> undirectedAdjacencyList(vector<vector<int>> adj_list, vector<vector<int>> E)
{
    for (int i = 0; i < no_E; i++)
    {
        if (E[i][0] != E[i][1])
        {
            int flag = 0;
            for (int j = 0; j < adj_list[E[i][0] - 1].size(); j++)
            {
                if (adj_list[E[i][0] - 1][j] == E[i][1])
                {
                    flag = 1;
                }
            }
            if (!flag)
            {
                adj_list[E[i][0] - 1].push_back(E[i][1]);
                adj_list[E[i][1] - 1].push_back(E[i][0]);
            }
        }
    }

    return adj_list;
}

vector<vector<int>> directedInputEdges(vector<vector<int>> E)
{
    for (int i = 0; i < no_E; i++)
    {
    tailDirectedEdges:
        int v1, v2;
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
        E.push_back(vector<int>());
        E[i].push_back(v1);
        E[i].push_back(v2);
    }

    return E;
}

vector<vector<int>> directedAdjacencyMatrix(vector<vector<int>> adj_mat, vector<vector<int>> E)
{
    for (int i = 0; i < V; i++)
    {
        adj_mat.push_back(vector<int>());
        for (int j = 0; j < V; j++)
        {
            adj_mat[i].push_back(0);
        }
    }

    for (int i = 0; i < no_E; i++)
    {
        if (E[i][0] != E[i][1])
        {
            if (adj_mat[E[i][0] - 1][E[i][1] - 1])
            {
                adj_mat[E[i][0] - 1][E[i][1] - 1] += 1;
            }
            else
            {
                adj_mat[E[i][0] - 1][E[i][1] - 1] = 1;
            }
        }
        else
        {
            if (adj_mat[E[i][0] - 1][E[i][0] - 1])
            {
                adj_mat[E[i][0] - 1][E[i][0] - 1] += 1;
            }
            else
            {
                adj_mat[E[i][0] - 1][E[i][0] - 1] = 1;
            }
        }
    }

    return adj_mat;
}

vector<vector<int>> directedAdjacencyList(vector<vector<int>> adj_list, vector<vector<int>> E)
{
    for (int i = 0; i < no_E; i++)
    {
        if (E[i][0] != E[i][1])
        {
            int flag = 0;
            for (int j = 0; j < adj_list[E[i][0] - 1].size(); j++)
            {
                if (adj_list[E[i][0] - 1][j] == E[i][1])
                {
                    flag = 1;
                }
            }
            if (!flag)
            {
                adj_list[E[i][0] - 1].push_back(E[i][1]);
            }
        }
    }

    return adj_list;
}

void dispAdjMatrix(vector<vector<int>> adj_mat)
{
    cout << "\n\nAdjacency matrix\n  | ";
    for (int i = 0; i < V; i++)
    {
        cout << i + 1 << " ";
    }
    cout << "\n--+";
    for (int i = 0; i < V; i++)
    {
        cout << "--";
    }
    cout << "\n";
    for (int i = 0; i < adj_mat.size(); i++)
    {
        cout << i + 1 << " | ";
        for (int j = 0; j < adj_mat[i].size(); j++)
        {
            cout << adj_mat[i][j] << " ";
        }
        cout << "\n";
    }
}

void dispAdjList(vector<vector<int>> adj_list)
{
    cout << "\n\nAdjacency List\nV\n";
    for (int i = 0; i < V; i++)
    {
        cout << i + 1 << " |";
        for (int j = 0; j < adj_list[i].size(); j++)
        {
            cout << " -> " << adj_list[i][j];
        }
        cout << endl;
    }
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

        cout << "\nEnter number of vertices: ";
        cin >> V;
        cout << "Enter number of edges: ";
        cin >> no_E;
        cout << "\nEnter vertices of given edges:\n";

        vector<vector<int>> E;
        vector<vector<int>> adj_mat;
        vector<vector<int>> adj_list(V, vector<int>());

        switch (opt)
        {
        case 1:
            E = directedInputEdges(E);
            adj_mat = directedAdjacencyMatrix(adj_mat, E);
            adj_list = directedAdjacencyList(adj_list, E);
            break;

        case 2:
            E = undirectedInputEdges(E);
            adj_mat = undirectedAdjacencyMatrix(adj_mat, E);
            adj_list = undirectedAdjacencyList(adj_list, E);
            break;
        }

        dispAdjMatrix(adj_mat);
        dispAdjList(adj_list);

        cout << "\nDo you want to try again (Y/N): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
