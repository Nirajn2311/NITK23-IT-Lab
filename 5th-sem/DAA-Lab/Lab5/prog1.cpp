#include <iostream>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

int minDistance(vector<int> dist, vector<bool> vis)
{
  int min = INT_MAX;
  int min_ind;
  for (int i = 0; i < 4; i++)
  {
    if (vis[i] == false && dist[i] <= min)
    {
      min = dist[i];
      min_ind = i;
    }
  }

  return min_ind;
}

void dijkstra(vector<vector<int>> mod_adj_mat, int u, int v)
{
  vector<bool> vis(4, false);
  vector<int> dist(4, INT_MAX);
  vector<int> path(4);
  dist[u] = 0;

  for (int i = 0; i < 3; i++)
  {
    int min_ind = minDistance(dist, vis);
    vis[min_ind] = true;
    for (int j = 0; j < 4; j++)
    {
      if (!vis[j] && mod_adj_mat[min_ind][j] != -1 && dist[min_ind] + mod_adj_mat[min_ind][j] < dist[j] && dist[min_ind] != INT_MAX)
      {
        dist[j] = dist[min_ind] + mod_adj_mat[min_ind][j];
        path[j] = min_ind;
      }
    }
  }

  if (dist[v] != INT_MAX)
  {
    int temp_arr[4];
    int x = 0;
    int a = v;
    temp_arr[0] = v;
    x++;

    do
    {
      temp_arr[x] = path[a];
      a = path[a];
      x++;
    } while (a != u);

    cout << "Shortest path from vertex " << u << " to " << v << " is: " << u;
    for (int z = x - 2; z >= 0; z--)
    {
      cout << " -> ";
      cout << temp_arr[z];
    }
    cout << endl;
  }
  else
  {
    cout << "Shortest path from vertex " << u << " to " << v << " is not possible to be found." << endl;
  }
}

void dijkstraToAll(vector<vector<int>> mod_adj_mat, int u)
{
  for (int i = 0; i < 4; i++)
  {
    if (i != u)
    {
      dijkstra(mod_adj_mat, u, i);
    }
  }
}

vector<int> bellmanFord(vector<vector<int>> &edge_mat, int adj_mat[][4])
{

  vector<int> dist(5, INT_MAX);
  vector<int> temp;
  dist[4] = 0;

  for (int i = 0; i < 4; i++)
  {
    temp.push_back(4);
    temp.push_back(i);
    temp.push_back(0);
    edge_mat.push_back(temp);
    temp.clear();
  }
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < edge_mat.size(); j++)
    {
      if ((dist[edge_mat[j][0]] != INT_MAX) && (dist[edge_mat[j][0]] + edge_mat[j][2] < dist[edge_mat[j][1]]))
      {
        dist[edge_mat[j][1]] = dist[edge_mat[j][0]] + edge_mat[j][2];
      }
    }
  }

  return dist;
}

void johnson(int adj_mat[][4])
{
  vector<vector<int>> edge_mat;
  vector<int> temp(3);
  vector<vector<int>> mod_adj_mat(4, vector<int>(4, 0));
  vector<int> dist;

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (adj_mat[i][j] != 0)
      {
        temp[0] = i;
        temp[1] = j;
        temp[2] = adj_mat[i][j];
        edge_mat.push_back(temp);
      }
    }
  }

  dist = bellmanFord(edge_mat, adj_mat);

  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (adj_mat[i][j] != 0)
      {
        mod_adj_mat[i][j] = adj_mat[i][j] + dist[i] - dist[j];
      }
      else
      {
        mod_adj_mat[i][j] = -1;
      }
    }
  }

  for (int i = 0; i < 4; i++)
  {
    cout << "SOURCE VERTEX " << i << endl;
    dijkstraToAll(mod_adj_mat, i);
    cout << endl;
  }
}

int main()
{
  int adj_mat[][4] = {{0, -5, 2, 3},
                      {0, 0, 4, 0},
                      {0, 0, 0, 1},
                      {0, 0, 0, 0}};

  johnson(adj_mat);
  return 0;
}