#include <bits/stdc++.h>
using namespace std;

// Define a Graph
class Graph
{
public:
    map<int, list<int>> graph; // Store a list of adjacent vertices corresponding to a vertex
    int n;                     // n = Number of Vertices in the Graph

    // Initialise Graph
    Graph(int k)
    {
        n = k;
    }

    // Add edges
    void addEdge(int a, int b, bool v)
    {
        graph[a].push_back(b);
        if (!v)
        {
            graph[b].push_back(a);
        }
    }

    // BFS
    int BFS(int startPoint, int *maxDiameter)
    {
        cout << "\nThe BFS Traversal of the graph is as follows: \n";
        map<int, bool> visited;
        map<int, int> diameter;
        for (auto it = graph.begin(); it != graph.end(); it++)
        {
            visited[it->first] = false;
            diameter[it->first] = 0;
        }

        queue<int> q;

        q.push(startPoint);
        visited[startPoint] = true;

        while (!q.empty())
        {

            startPoint = q.front();
            cout << startPoint << " ";
            q.pop();

            for (int x : graph[startPoint])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    diameter[x] += diameter[startPoint] + 1;
                    q.push(x);
                }
            }
        }

        *maxDiameter = 0;
        int e;

        for (auto it = graph.begin(); it != graph.end(); it++)
        {
            if (*maxDiameter < diameter[it->first])
            {
                *maxDiameter = diameter[it->first];
                e = it->first;
            }
        }

        cout << endl;
        return e;
    }

    // List all nodes at max length from starting node
    list<int> bfsHelper(int startPoint)
    {
        cout << "\nThe BFS Traversal of the graph is as follows: \n";
        map<int, bool> visited;
        map<int, int> diameter;
        for (auto it = graph.begin(); it != graph.end(); it++)
        {
            visited[it->first] = false;
            diameter[it->first] = 0;
        }

        queue<int> q;

        q.push(startPoint);
        visited[startPoint] = true;

        while (!q.empty())
        {

            startPoint = q.front();
            cout << startPoint << " ";
            q.pop();

            for (int x : graph[startPoint])
            {
                if (!visited[x])
                {
                    visited[x] = true;
                    diameter[x] += diameter[startPoint] + 1;
                    q.push(x);
                }
            }
        }

        int maxDiameter = 0;
        list<int> maxDiameterNodes;

        for (auto it = graph.begin(); it != graph.end(); it++)
        {
            if (maxDiameter < diameter[it->first])
            {
                maxDiameter = diameter[it->first];
                maxDiameterNodes.clear();
            }
            if (maxDiameter == diameter[it->first])
            {
                maxDiameterNodes.push_back(it->first);
            }
        }

        cout << endl;
        return maxDiameterNodes;
    }

    // Diameter of graph
    void graphDiameter(int st)
    {
        int d = 0, maxD = 0, oldMaxD = 0, ending = 0, starting = 0;
        list<int> beginning = bfsHelper(st);
        for (int x : beginning)
        {
            oldMaxD = maxD;
            d = BFS(x, &maxD);
            if (oldMaxD <= maxD)
            {
                oldMaxD = maxD;
                ending = d;
                starting = x;
            }
        }
        cout << "\nDiameter of the graph is " << oldMaxD << " from vertice " << starting << " to " << ending << endl;
    }
};

/*  
	ASSUMPTION: All nodes of the graph are integers.
	
	Queues are used for BFS.
*/

int main()
{
    int num, edges;
    int ch;
    bool val;

again:
    cout << "Choose type of graph:\n  1. Undirected\n  2. Directed\n Choose: ";
    cin >> ch;

    cout << "Enter the number of nodes: ";
    cin >> num;

    Graph graph(num);

    switch (ch)
    {
    case 1:
        val = false;
        break;
    case 2:
        val = true;
        break;
    default:
        goto again;
    }

    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0, a, b; i < edges; i++)
    {

        // ASSUMPTION: In case of directed graphs, vertex 1 is tail, and vertex 2 is head
        cout << "Enter first vertex of edge " << i + 1 << "  : ";
        cin >> a;
        cout << "Enter second vertex of edge " << i + 1 << " : ";
        cin >> b;

        cout << endl;

        graph.addEdge(a, b, val);
    }

    int s;

    cout << "Enter Start Point: ";
    cin >> s;

    graph.graphDiameter(s);

    return 0;
}