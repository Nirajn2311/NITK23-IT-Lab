#include <bits/stdc++.h>

#define D 4
#define Q 19

using namespace std;
int part;

void makePI(int pi[], int m, string pattern)
{
    int j = 0;
    int i = 1;
    pi[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[j])
        {
            j++;
            pi[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                pi[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string pattern, string str)
{
    int m = pattern.size();
    int n = str.size();
    int pi[m];
    int i = 0, j = 0;
    int flag = 1;

    makePI(pi, m, pattern);

    while (i < n)
    {
        if (str[i] == pattern[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << i - m << " ";
            j = 0;
            flag = 0;
        }
        else if (str[i] != pattern[j])
        {
            if (j != 0)
            {
                j = pi[j - 1];
            }
            else
            {
                i++;
            }
        }
    }

    if (flag)
    {
        cout << "Pattern Not Found" << endl;
    }
    else
    {
        cout << endl;
    }
}

void rabinkarp(string pattern, string str)
{
    int m = pattern.size();
    int n = str.size();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    int flag = 1;

    for (i = 0; i < m - 1; i++)
    {
        h = (h * D) % Q;
    }

    for (i = 0; i < m; i++)
    {
        p = (D * p + pattern[i]) % Q;
    }
    for (i = 0; i < m; i++)
    {
        t = (D * t + str[i]) % Q;
    }

    for (i = 0; i <= n - m; i++)
    {
        if (p == t)
        {
            for (j = 0; j < m; j++)
            {
                if (str[i + j] != pattern[j])
                {
                    break;
                }
            }

            if (j == m)
            {
                cout << i << " ";
                flag = 0;
            }
        }
        if (i < n - m)
        {
            t = (D * (t - str[i] * h) + str[i + m]) % Q;
            if (t < 0)
            {
                t = (t + Q);
            }
        }
    }

    if (flag)
    {
        cout << "Pattern Not Found " << endl;
    }
    else
    {
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    fstream fp;
    string pattern, line;
    int lim;

    part = stoi(argv[1]);
    fp.open(argv[2], ios::in);
    getline(fp, pattern);

    getline(fp, line);
    lim = stoi(line);

    switch (part)
    {
    case 1:
    {
        for (int i = 0; i < lim; i++)
        {
            getline(fp, line);
            kmp(pattern, line);
        }
        break;
    }
    case 2:
    {
        for (int i = 0; i < lim; i++)
        {
            getline(fp, line);
            rabinkarp(pattern, line);
        }
        break;
    }
    }
}