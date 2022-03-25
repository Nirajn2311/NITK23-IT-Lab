#include <bits/stdc++.h>

using namespace std;
int V, no_E, graph_type = 0, startNode = 0;
// V: Number of vertices from user
// no_E: Number of edges from user
// graph_type: 1 is for Directed Graph and 0 for Undirected Graph
// startNode: Start DFS at Vertex 0

struct AdjListNode
{
    int d;
    AdjListNode *next;
};

class AdjList
{
private:
    AdjListNode **adj_list;
    int n;

    void freeSpace(AdjListNode *n)
    {
        if (n == nullptr)
        {
            return;
        }
        else
        {
            freeSpace(n->next);
            delete n;
        }
    }

public:
    AdjList(int no_V)
    {
        n = no_V;
        adj_list = new AdjListNode *[n];

        for (int i = 0; i < n; i++)
        {
            adj_list[i] = new AdjListNode;
            adj_list[i]->d = i;
            adj_list[i]->next = nullptr;
        }
    }

    void addEdge(int v1, int v2)
    {
        AdjListNode *node1 = new AdjListNode;
        AdjListNode *temp = adj_list[v1 - 1];
        node1->d = v2 - 1;
        node1->next = nullptr;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = node1;

        if (!graph_type)
        {
            AdjListNode *node2 = new AdjListNode;
            node2->d = v1 - 1;
            node2->next = nullptr;
            temp = adj_list[v2 - 1];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = node2;
        }
    }

    void DFS(int start)
    {
        int queue[n], val = -1, time = 0, vis[n], parent[n], T[n], sp, ep;
        bool visited[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            visited[i] = 0;
            vis[i] = INT_MAX;
        }
        ep = 0;
        sp = 0;
        queue[0] = start;
        AdjListNode *temp;
        while (ep >= 0)
        {
            val = queue[ep];
            temp = adj_list[val];
            ep--;
            if (!visited[val])
            {
                visited[val] = 1;
                vis[val] = time++;
                T[sp++] = val;
            }
            while (temp->next != nullptr)
            {
                if (!visited[temp->d])
                {
                    ep++;
                    queue[ep] = temp->d;
                    parent[temp->d] = val;
                }
                temp = temp->next;
            }
            if (!visited[temp->d])
            {
                ep++;
                queue[ep] = temp->d;
                parent[temp->d] = val;
            }
        }
        bool notTwoEdge = false;
        int t;
        for (int i = sp - 1; i > 0; i--)
        {
            temp = adj_list[T[i]];
            val = T[i];
            t = vis[val];
            while (temp->next != nullptr)
            {
                if (t > vis[temp->d] && temp->d != parent[val])
                    t = vis[temp->d];
                temp = temp->next;
            }
            if (t > vis[temp->d] && temp->d != parent[val])
                t = vis[temp->d];
            if (vis[val] == t)
            {
                if (!notTwoEdge)
                {
                    cout << "\n\nThis isn't a 2-Edge connected graph\nBridge Edges:\n";
                    notTwoEdge = true;
                }
                cout << parent[val] + 1 << " -> " << val + 1 << endl;
            }
            else
                vis[val] = t;
        }
        if (!notTwoEdge)
            cout << "\n\nThis is a 2-Edge connected graph\n";
    }

    ~AdjList()
    {
        for (int i = 0; i < n; i++)
        {
            freeSpace(adj_list[i]);
        }
        delete[] adj_list;
    }
};

int main()
{
    int opt, v1, v2;
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

    AdjList adj_list(V);

    cout << "\nEnter vertice number between 1 and " << V << endl;
    for (int i = 0; i < no_E; i++)
    {
        cout << "Enter the edge " << i + 1 << ": ";
        cin >> v1 >> v2;
        adj_list.addEdge(v1, v2);
    }

    adj_list.DFS(startNode);

    return 0;
}