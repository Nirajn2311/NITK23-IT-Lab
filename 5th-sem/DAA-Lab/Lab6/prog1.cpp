#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int minPlatforms(vector<int> arrival, vector<int> departure, int n)
{
  int plat = 1, result = 1, i = 1, j = 0;

  sort(arrival.begin(), arrival.end());
  sort(departure.begin(), departure.end());

  while (i < n && j < n)
  {
    if (arrival[i] <= departure[j])
    {
      plat++;
      i++;
    }
    else
    {
      plat--;
      j++;
    }
    result = max(result, plat);
  }
  return result;
}

int main()
{
  int n, platforms;

  cout << "Enter number of inputs of arrival and departure times: ";
  cin >> n;
  vector<int> arrival(n);
  vector<int> departure(n);

  cout << "\nEnter the time in 24hr format without ':' between hour and minute group.";
  for (int i = 0; i < n; i++)
  {
    cout << "\n\nEnter arrival time for train " << i + 1 << ": ";
    cin >> arrival[i];
    cout << "Enter departure time for train " << i + 1 << ": ";
    cin >> departure[i];
  }

  platforms = minPlatforms(arrival, departure, n);
  cout << "\nMinimum number of platforms required: " << platforms << endl;
  return 0;
}