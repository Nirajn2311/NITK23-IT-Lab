#include <bits/stdc++.h>

using namespace std;
int part;

struct Node
{
    int index;
    Node *A = NULL;
    Node *C = NULL;
    Node *G = NULL;
    Node *T = NULL;
    bool wordEnd = false;
};

Node *newNode(int index)
{
    Node *letter = new Node;
    letter->index = index;
    return letter;
}

void trieCreation(int lim, string str[], Node *root)
{
    int count = 1;
    for (int i = 0; i < lim; i++)
    {
        Node *temp = root;
        for (int j = 0; j < str[i].length(); j++)
        {
            char t = str[i][j];
            switch (t)
            {
            case 'A':
                if (temp->A == NULL)
                {
                    if (part == 1)
                        cout << temp->index << "->" << count << ":A" << endl;
                    temp->A = newNode(count);
                    count++;
                    temp = temp->A;
                }
                else
                {
                    temp = temp->A;
                }
                break;
            case 'C':
                if (temp->C == NULL)
                {
                    if (part == 1)
                        cout << temp->index << "->" << count << ":C" << endl;
                    temp->C = newNode(count);
                    count++;
                    temp = temp->C;
                }
                else
                {
                    temp = temp->C;
                }
                break;
            case 'G':
                if (temp->G == NULL)
                {
                    if (part == 1)
                        cout << temp->index << "->" << count << ":G" << endl;
                    temp->G = newNode(count);
                    count++;
                    temp = temp->G;
                }
                else
                {
                    temp = temp->G;
                }
                break;
            case 'T':
                if (temp->T == NULL)
                {
                    if (part == 1)
                        cout << temp->index << "->" << count << ":T" << endl;
                    temp->T = newNode(count);
                    count++;
                    temp = temp->T;
                }
                else
                {
                    temp = temp->T;
                }
                break;
            }
        }
        temp->wordEnd = true;
    }
}

void patternSearch(string text, Node *root)
{
    for (int i = 0; i < text.length(); i++)
    {
        int flag = 1;
        int pos = i;
        Node *temp = root;

        for (int j = i; j < text.length(); j++)
        {
            if (text[j] == 'A')
            {
                if (temp->A == NULL)
                {
                    flag = 0;
                    break;
                }
                else if (temp->A->wordEnd)
                {
                    break;
                }
                else if (!temp->A->wordEnd)
                {
                    temp = temp->A;
                }
            }
            else if (text[j] == 'C')
            {
                if (temp->C == NULL)
                {
                    flag = 0;
                    break;
                }
                else if (temp->C->wordEnd)
                {
                    break;
                }
                else if (!temp->C->wordEnd)
                {
                    temp = temp->C;
                }
            }
            else if (text[j] == 'G')
            {
                if (temp->G == NULL)
                {
                    flag = 0;
                    break;
                }
                else if (temp->G->wordEnd)
                {
                    break;
                }
                else if (!temp->G->wordEnd)
                {
                    temp = temp->G;
                }
            }
            else if (text[j] == 'T')
            {
                if (temp->T == NULL)
                {
                    flag = 0;
                    break;
                }
                else if (temp->T->wordEnd)
                {
                    break;
                }
                else if (!temp->T->wordEnd)
                {
                    temp = temp->T;
                }
            }
        }
        if (flag)
        {
            cout << pos << " ";
        }
    }
}

int main(int argc, char *argv[])
{
    fstream fp;
    int lim;
    Node *root = newNode(0);
    string line, str[5000];

    part = stoi(argv[1]);
    fp.open(argv[2], ios::in);
    switch (part)
    {
    case 1:
    {
        getline(fp, line);
        lim = stoi(line);

        for (int i = 0; i < lim; i++)
        {
            getline(fp, line);
            str[i] = line;
        }

        trieCreation(lim, str, root);

        break;
    }

    case 2:
    {
        string text;
        getline(fp, text);

        getline(fp, line);
        lim = stoi(line);

        for (int i = 0; i < lim; i++)
        {
            getline(fp, line);
            str[i] = line;
        }

        trieCreation(lim, str, root);

        patternSearch(text, root);

        break;
    }

    case 3:
    {
        string text;
        getline(fp, text);

        getline(fp, line);
        lim = stoi(line);

        for (int i = 0; i < lim; i++)
        {
            getline(fp, line);
            str[i] = line;
        }

        trieCreation(lim, str, root);

        patternSearch(text, root);

        break;
    }
    }

    cout << endl;
    fp.close();
    return 0;
}