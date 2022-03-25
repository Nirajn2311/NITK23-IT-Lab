#include <iostream>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

void floydWarshall(int no_V, vector<vector<int>> &dist, vector<vector<int>> &next)
{
  for (int k = 0; k < no_V; k++)
  {
    if (k == 1 || k == 3 || k == 5)
    {
      cout << "\n\nValues of dist(i,j) at k = " << k << ": " << endl;
      for (int m = 0; m < no_V; m++)
      {
        for (int n = 0; n < no_V; n++)
        {
          cout << dist[m][n] << " ";
        }
        cout << endl;
      }
    }

    for (int i = 0; i < no_V; i++)
    {
      for (int j = 0; j < no_V; j++)
      {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
        {
          continue;
        }

        if (dist[i][j] > dist[i][k] + dist[k][j])
        {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
        }
      }
    }
  }
}

vector<int> constrPath(int u, int v, vector<vector<int>> next)
{
  vector<int> result;

  if (next[u][v] == -1)
  {
    return {};
  }
  result.push_back(u);

  while (u != v)
  {
    u = next[u][v];
    result.push_back(u);
  }

  return result;
}

int main()
{
  int no_V, no_E, source, dest, wt, n;
  vector<int> path;

  cout << "Enter number of vertices: ";
  cin >> no_V;
  cout << "Enter number of edges: ";
  cin >> no_E;

  vector<vector<int>> adj_mat(no_V, vector<int>(no_V, INT_MAX));
  vector<vector<int>> dist(no_V, vector<int>(no_V));
  vector<vector<int>> next(no_V, vector<int>(no_V));

  for (int i = 1; i <= no_E; i++)
  {
    cout << "\nEdge number " << i;
    cout << "\nEnter source vertex: ";
    cin >> source;
    cout << "Enter destination vertex: ";
    cin >> dest;
    cout << "Enter weight: ";
    cin >> wt;
    adj_mat[source][dest] = wt;
    adj_mat[dest][source] = wt;
  }

  for (int i = 0; i < no_V; i++)
  {
    for (int j = 0; j < no_V; j++)
    {
      if (i == j)
        adj_mat[i][j] = 0;
    }
  }

  cout << "\n\nInitial values of dist(i,j): " << endl;
  for (int i = 0; i < no_V; i++)
  {
    for (int j = 0; j < no_V; j++)
    {
      dist[i][j] = adj_mat[i][j];
      cout << dist[i][j] << " ";
      if (adj_mat[i][j] == INT_MAX)
      {
        next[i][j] = -1;
      }
      else
      {
        next[i][j] = j;
      }
    }
    cout << endl;
  }

  floydWarshall(no_V, dist, next);

  cout << "\n\nFinal value of dist(i,j): " << endl;
  for (int m = 0; m < no_V; m++)
  {
    for (int n = 0; n < no_V; n++)
    {
      cout << dist[m][n] << " ";
    }
    cout << endl;
  }

  cout << "\n\nEnter source vertex: ";
  cin >> source;
  cout << "Enter destination vertex: ";
  cin >> dest;
  path = constrPath(source, dest, next);
  cout << "Shortest path from vertex " << source << " to " << dest << " is: " << path[0];
  for (int i = 1; i < path.size(); i++)
  {
    cout << " -> " << path[i];
  }
  cout << endl;

  return 0;
}
