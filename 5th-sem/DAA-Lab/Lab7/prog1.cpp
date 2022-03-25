#include <iostream>
#include <queue>
#include <set>
#include <stdio.h>

using namespace std;

int shortestChainLength(string start, string end, set<string> wordDict)
{
  if (start == end || wordDict.find(end) == wordDict.end())
  {
    return 0;
  }

  int lvl = 0, wLen = start.size(), size;
  string word;
  char orig_char;
  queue<string> Q;

  Q.push(start);
  while (!Q.empty())
  {
    lvl++;
    size = Q.size();
    for (int i = 0; i < size; i++)
    {
      word = Q.front();
      Q.pop();
      for (int pos = 0; pos < wLen; ++pos)
      {
        orig_char = word[pos];
        for (char c = 'a'; c <= 'z'; ++c)
        {
          word[pos] = c;
          if (word == end)
          {
            return lvl + 1;
          }
          if (wordDict.find(word) == wordDict.end())
          {
            continue;
          }
          Q.push(word);
          wordDict.erase(word);
        }
        word[pos] = orig_char;
      }
    }
  }

  return 0;
}

int main()
{
  int n;
  string start, end, temp;
  set<string> wordDict;

  cout << "Enter number of words: ";
  cin >> n;
  cout << endl;

  for (int i = 0; i < n; i++)
  {
    cout << "Enter word " << i + 1 << ": ";
    cin >> temp;
    wordDict.insert(temp);
  }

  cout << "\nEnter starting word: ";
  cin >> start;
  cout << "Enter ending word: ";
  cin >> end;
  cout << "\nLength of shortest chain of words: " << shortestChainLength(start, end, wordDict) << endl;

  return 0;
}