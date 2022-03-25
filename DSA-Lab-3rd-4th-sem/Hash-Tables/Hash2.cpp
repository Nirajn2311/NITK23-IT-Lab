#include <bits/stdc++.h>

#define MAX 100000

using namespace std;

string Hash[MAX];

int hashFunc(string s)
{

    int sum = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        sum += (int(s[i]) * pow(11, i + 1));
    }
    return sum;
}

void insert_data(string s, int loca)
{
    int inserted = 0;
    for (int i = 0; inserted == 0; i++)
    {
        if (Hash[loca + i].empty())
        {
            Hash[loca + i] = s;
            inserted = 1;
        }
        if (loca + i == MAX)
        {
            loca = 0;
            i = 0;
        }
    }
}

void delete_data(int loca)
{
    if (Hash[loca].empty())
    {
        return;
    }
    Hash[loca].clear();
}

void search_data(string s, int loca)
{
    int found = 0;
    for (int i = 0; found == 0; i++)
    {
        if (Hash[loca + i].compare(s) == 0)
        {
            found = 1;
            return;
        }
        if (loca + i == MAX)
        {
            loca = 0;
            i = 0;
        }
        if (Hash[loca + i].empty())
        {
            return;
        }
    }
}

int main()
{
    int current_size = 0;
    while (current_size <= 80000)
    {
        srand((unsigned)time(0));
        for (int i = 0; i < 7; i++)
        {
            int x = abs(rand() * 99999 / RAND_MAX);
            int loca = hashFunc(to_string(x));
            if (loca > MAX)
            {
                loca = loca % MAX;
            }
            insert_data(to_string(x), loca);
            current_size++;
        }

        for (int i = 0; i < 2; i++)
        {
            int x = abs(rand() * 99999 / RAND_MAX);
            int loca = hashFunc(to_string(x));
            if (loca > MAX)
            {
                loca = loca % MAX;
            }
            delete_data(loca);
            current_size--;
        }

        for (int i = 0; i < 1; i++)
        {
            chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
            srand((unsigned)time(0));
            int x = abs(rand() * 99999 / RAND_MAX);
            int loca = hashFunc(to_string(x));
            if (loca > MAX)
            {
                loca = loca % MAX;
            }
            search_data(to_string(x), loca);
            chrono::high_resolution_clock::time_point stop = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> searchtime = stop - start;
            cout << "No of elements inserted: " << current_size << "\t" << float(searchtime.count()) << endl;
        }
    }
    return 0;
}