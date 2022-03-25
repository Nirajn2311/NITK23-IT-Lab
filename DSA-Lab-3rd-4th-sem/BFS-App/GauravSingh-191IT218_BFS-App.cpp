#include <bits/stdc++.h>
using namespace std;

int bfs(vector<int> adj[], int start, int v)
{
  list<int> queue_structure;
  int current_vertex;
  vector<int> explored_vertices;
  queue_structure.push_back(start);
  explored_vertices.push_back(start);
  vector<int> level(v + 1, -1);
  while (queue_structure.empty() == false)
  {
    current_vertex = queue_structure.front();
    queue_structure.pop_front();
    if (level[current_vertex] == -1)
    {
      level[current_vertex] = 0;
    }
    vector<int>::iterator it;
    int i = 0;
    while (i < adj[current_vertex].size())
    {
      it = find(explored_vertices.begin(), explored_vertices.end(), adj[current_vertex][i]);
      if (it == explored_vertices.end())
      {
        explored_vertices.push_back(adj[current_vertex][i]);
        queue_structure.push_back(adj[current_vertex][i]);
        if (level[adj[current_vertex][i]] == -1)
          level[adj[current_vertex][i]] = level[current_vertex] + 1;
      }
      i++;
    }
  }
  return *max_element(level.begin(), level.end());
}

int main()
{
  int v, e;
  cout << "Enter the number of vertices: ";
  cin >> v;
  cout << "Enter the number of edges: ";
  cin >> e;
  vector<int> adj[v + 1];
  for (int i = 0; i < e; i++)
  {
    int x, y;
    cout << "Enter the vertices of any edge: " << endl;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int maxdiameter = 0;
  int tempdiameter;
  for (int i = 1; i <= v; i++)
  {
    tempdiameter = bfs(adj, i, v);
    if (tempdiameter > maxdiameter)
    {
      maxdiameter = tempdiameter;
    }
  }
  cout << "The diameter is " << maxdiameter;
  return 0;
}