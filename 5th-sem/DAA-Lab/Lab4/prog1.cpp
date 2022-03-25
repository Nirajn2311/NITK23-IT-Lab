#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <stdio.h>
#include <vector>

using namespace std;

map<double, string> ma;

struct Edge
{
  double source, dest, act_cost, weight;
};

void printPath(vector<double> const &parent, double vertex, double d)
{
  if (vertex < 0)
  {
    return;
  }

  printPath(parent, parent[vertex], d);

  if (vertex != d)
  {
    cout << ma[vertex] << " -> ";
  }
  else
  {
    cout << ma[vertex];
  }
}

void bellmanFord(vector<Edge> const &edges, double source, double destination, double N)
{
  double u, v, w, k = N;
  vector<double> distance(N, INT_MAX);
  vector<double> parent(N, -1);

  distance[source] = 0;

  while (--k)
  {
    for (Edge edge : edges)
    {
      u = edge.source;
      v = edge.dest;
      w = edge.weight;

      if (distance[u] != INT_MAX && distance[u] + w < distance[v])
      {
        distance[v] = distance[u] + w;
        parent[v] = u;
      }
    }
  }

  for (Edge edge : edges)
  {
    u = edge.source;
    v = edge.dest;
    w = edge.weight;

    if (distance[u] != INT_MAX && distance[u] + w < distance[v])
    {
      cout << "Negative-weight cycle is found!!";
      return;
    }
  }

  cout << "\n1 " << ma[source] << " = " << pow(10, -1 * distance[destination]) << " " << ma[destination] << "\nIts path of conversion is ";
  printPath(parent, destination, destination);
  cout << endl;
}

int main()
{
  double N = 10;
  vector<Edge> edges;
  ma[0] = "Gold";
  ma[1] = "US Dollar";
  ma[2] = "Swiss Franc";
  ma[3] = "Japanese Yen";
  ma[4] = "Euro";
  ma[5] = "UK Pound";
  ma[6] = "Canadian Dollar";
  ma[7] = "Mexican Peso";
  ma[8] = "New Zealand Dollar";
  ma[9] = "Pakistani Rupee";

  edges.push_back({0, 1, 327.25, (double)(-1 * log10(327.25))});
  edges.push_back({0, 2, 455.2, (double)(-1 * log10(455.2))});
  edges.push_back({0, 5, 208.1, (double)(-1 * log10(208.1))});
  edges.push_back({2, 1, 0.7182, (double)(-1 * log10(0.7182))});
  edges.push_back({2, 4, 0.6677, (double)(-1 * log10(0.6677))});
  edges.push_back({3, 1, 0.008309, (double)(-1 * log10(0.008309))});
  edges.push_back({4, 1, 1.0752, (double)(-1 * log10(1.0752))});
  edges.push_back({4, 3, 129.52, (double)(-1 * log10(129.52))});
  edges.push_back({5, 2, 2.1904, (double)(-1 * log10(2.1904))});
  edges.push_back({1, 7, 20.58, (double)(-1 * log10(20.58))});
  edges.push_back({1, 8, 1.45, (double)(-1 * log10(1.45))});
  edges.push_back({7, 8, 0.07, (double)(-1 * log10(0.07))});
  edges.push_back({4, 6, 1.47, (double)(-1 * log10(1.47))});
  edges.push_back({6, 8, 1.14, (double)(-1 * log10(1.14))});
  edges.push_back({6, 9, 134.10, (double)(-1 * log10(134.10))});

  double source, destination;
  cout << "Currencies available are: \n1.Gold\n2.US Dollar\n3.Swiss Franc\n4.Japanese Yen\n5.Euro\n6.UK Pound\n7.Canadian Dollar\n8.Mexican Peso\n9.New Zealand Dollar\n10.Pakistani Rupee";
  cout << "\n\nEnter input currency option number: ";
  cin >> source;
  cout << "Enter output currency option number: ";
  cin >> destination;
  bellmanFord(edges, source - 1, destination - 1, N);

  return 0;
}