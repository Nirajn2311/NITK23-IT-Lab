#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;
int V, no_E, startNode;
// V: Number of vertices from user
// no_E: Number of edges from user
// startNode: Start Dijkstra at inputted Vertex

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

  cout << "\nShortest cost from routers " << start << " to " << dest << ": " << distance[dest] << endl;

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

  cout << "Shortest path from routers " << start << " to " << dest << ": ";
  cout << start;

  for (int z = x - 2; z >= 0; z--)
  {
    cout << " -> ";
    cout << tempArr[z];
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
  int v1, v2, weight;
  int i;

  cout << "Enter the number of routers(max 50): ";
  cin >> V;
  cout << "Enter the number of connections: ";
  cin >> no_E;

  if (V > 50 || V <= 0 || no_E <= 0)
  {
    cout << "\nNo routers present or no connections present.\n";
    return 0;
  }
  if (V == 1)
  {
    cout << "\nOnly one router present in network.\n";
    return 0;
  }

  int adj_matrix[50][50];
  for (i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      adj_matrix[i][j] = 0;
    }
  }

  cout << "\nEnter router number between 0 and " << V - 1;
  for (i = 1; i <= no_E; i++)
  {
    cout << "\nConnection " << i << ":\n";
    cin >> v1 >> v2;
    cout << "Enter cost: ";
    cin >> weight;
    adj_matrix[v1][v2] = weight;
    adj_matrix[v2][v1] = weight;
  }

  do
  {
    cout << "\nEnter source router number: ";
    cin >> startNode;
  } while (startNode < 0 || startNode >= V);

  dijkstraToAll(adj_matrix, startNode);
  return 0;
}