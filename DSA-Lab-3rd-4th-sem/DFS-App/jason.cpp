#include <bits/stdc++.h>

using namespace std;

struct AdjListNode
{
    int val;
    AdjListNode *next;
};

class AList
{
private:
    AdjListNode **list;
    int n;

    void freeup(AdjListNode *a)
    {
        if (a == nullptr)
            return;
        else
        {
            freeup(a->next);
            delete a;
        }
    }

public:
    AList(int k)
    {
        n = k;
        list = new AdjListNode *[n];
        for (int i = 0; i < n; i++)
        {
            list[i] = new AdjListNode;
            list[i]->val = i;
            list[i]->next = nullptr;
        }
    }

    void addEdge(int a, int b, bool v)
    {
        AdjListNode *val = new AdjListNode;
        val->val = b - 1;
        val->next = nullptr;
        AdjListNode *temp = list[a - 1];
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = val;

        if (!v)
        {
            AdjListNode *value = new AdjListNode;
            value->val = a - 1;
            value->next = nullptr;
            temp = list[b - 1];
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = value;
        }
    }

    void DFS(int start)
    {
        int queue[n], ep, val = -1, time = 0, dis[n], par[n], Q[n], sp;
        bool discovered[n];
        for (int i = 0; i < n; i++)
        {
            par[i] = -1;
            discovered[i] = 0;
            dis[i] = INT_MAX;
        }
        ep = 0;
        sp = 0;
        queue[0] = start;
        AdjListNode *temp;
        while (ep >= 0)
        {
            val = queue[ep];
            temp = list[val];
            ep--;
            if (!discovered[val])
            {
                discovered[val] = 1;
                dis[val] = time++;
                Q[sp++] = val;
            }
            while (temp->next != nullptr)
            {
                if (!discovered[temp->val])
                {
                    ep++;
                    queue[ep] = temp->val;
                    par[temp->val] = val;
                }
                // else low[val] = min(low[val], dis[temp->val]);
                temp = temp->next;
            }
            if (!discovered[temp->val])
            {
                ep++;
                queue[ep] = temp->val;
                par[temp->val] = val;
            }
            // else low[val] = min(low[val], dis[temp->val]);
        }
        // for (int i = 0; i < n; i++) cout << Q[i] << " ";
        // cout << endl;
        bool not_te = false;
        for (int i = sp - 1, t; i > 0; i--)
        {
            temp = list[Q[i]];
            val = Q[i];
            t = dis[val];
            while (temp->next != nullptr)
            {
                if (t > dis[temp->val] && temp->val != par[val])
                    t = dis[temp->val];
                temp = temp->next;
            }
            if (t > dis[temp->val] && temp->val != par[val])
                t = dis[temp->val];
            if (dis[val] == t)
            {
                if (!not_te)
                {
                    cout << "This isnt a 2-Edge connected graph\n";
                    not_te = true;
                }
                cout << par[val] + 1 << " " << val + 1 << endl;
            }
            else
                dis[val] = t;
        }
        if (!not_te)
            cout << "This is a 2-Edge connected graph\n";
        /*
        int i, j;
        for (i = 0, j = 0; i < n; i++)
        {
            //if (dis[par[i]] > low[i]) cout << par[i] << " " << i << endl;
            cout << i+1 << " " << par[i]+1 << " "  << low[i] << " " << dis[i] << endl;
        }
        // if (j == 0) cout << "This is an 2-edge connected graph" << endl;
        cout << endl;
        */
    }

    void Display()
    {
        cout << "Graph stored in Adjacency list\n Bridge Edges are:\n";
        AdjListNode *temp;
        for (int i = 0; i < n; i++)
        {
            temp = list[i];
            while (temp->next != nullptr)
            {
                cout << temp->val + 1 << " --> ";
                temp = temp->next;
            }
            cout << temp->val + 1 << endl;
        }
    }

    ~AList()
    {
        for (int i = 0; i < n; i++)
        {
            freeup(list[i]);
        }
        delete[] list;
    }
};

int main()
{
    int n, e;
    bool val;
    cout << "Is the graph directed?(0/1): ";
    cin >> val;
    cout << "Enter the number of nodes: ";
    cin >> n;
    AList l(n);

    cout << "Enter the number of edges: ";
    cin >> e;

    for (int i = 0, a, b; i < e; i++)
    {
        cout << "Enter the edge " << i + 1 << ": ";
        cin >> a >> b;
        l.addEdge(a, b, val);
    }

    l.Display();
    cout << endl;
    l.DFS(0);
}