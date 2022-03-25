#include <iostream>
#include <stdio.h>

using namespace std;

void minRefills(int d, int m, int n, int gas[])
{
  int refills = 0, curr = 0, limit = m;
  while (limit < d)
  {
    if (curr >= n || gas[curr] > limit)
    {
      cout << "-1" << endl;
      return;
    }
    while (curr < n - 1 && gas[curr + 1] <= limit)
    {
      curr++;
    }
    refills++;
    limit = gas[curr] + m;
    curr++;
  }
  cout << refills << endl;
}

int main()
{
  int d, m, n, gas[n];
  cout << "Enter distance of your destination: ";
  cin >> d;
  cout << "Enter max distance your car can travel on a full tank: ";
  cin >> m;
  cout << "Enter number of gas stations: ";
  cin >> n;
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter distance of gas station " << i + 1 << ": ";
    cin >> gas[i];
  }

  cout << "\nMinimum number of refills: ";
  minRefills(d, m, n, gas);

  return 0;
}
