#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool compFunc(string x, string y)
{
  string YX = y.append(x);
  string XY = x.append(y);
  return XY.compare(YX) > 0 ? 1 : 0;
}

void maxSalary(vector<string> inpArr)
{
  sort(inpArr.begin(), inpArr.end(), compFunc);
  for (int i = 0; i < inpArr.size(); i++)
  {
    cout << inpArr[i];
  }
}

int main()
{
  int n, inp[n];
  string temp;
  vector<string> inpArr;

  cout << "Enter number of numbers: ";
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter number " << i + 1 << ": ";
    cin >> temp;
    inpArr.push_back(temp);
  }

  cout << "\nMaximum salary: ";
  maxSalary(inpArr);
  cout << endl;

  return 0;
}
