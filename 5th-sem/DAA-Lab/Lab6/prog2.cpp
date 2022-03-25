#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct performance
{
  int s;
  int f;
};

bool compFunc(performance m1, performance m2)
{
  return m1.f < m2.f;
}

void interval_scheduling(vector<performance> arr, int n)
{
  int pos = 0;
  
  sort(arr.begin(), arr.end(), compFunc);
  cout << "\nThe following intervals are selected : ";
  cout << "(" << arr[0].s << ", " << arr[0].f << ") ";
  
  for (int i = 1; i < n; i++)
  {
    if (arr[i].s >= arr[pos].f)
    {
      cout << "(" << arr[i].s << ", " << arr[i].f << ") ";
      pos = i;
    }
  }
}

int main()
{
  int n;

  cout << "Enter number of intervals: ";
  cin >> n;
  vector<performance> arr(n);

  for (int i = 0; i < n; i++)
  {
    cout << "\nEnter the start time of interval " << i + 1 << ": ";
    cin >> arr[i].s;
    cout << "Enter the finish time of interval " << i + 1 << ": ";
    cin >> arr[i].f;
  }

  interval_scheduling(arr, n);
  cout << endl;
  return 0;
}