#include <bits/stdc++.h>

using namespace std;

struct Node
{
    char symbol = '0';
    int freq = 0;
    Node *left = NULL, *right = NULL;
};

struct MinHeap
{
    int heap_size = 0;
    Node **elements;
};

void mapCharCode(Node *root, int top, string code, map<char, string> &charCode)
{
    if (root->left)
    {
        code.insert(top, 1, '0');
        mapCharCode(root->left, top + 1, code, charCode);
    }

    if (root->right)
    {
        code.insert(top, 1, '1');
        mapCharCode(root->right, top + 1, code, charCode);
    }

    if (root->symbol != '0')
    {
        charCode[root->symbol] = code.substr(0, top);
    }
}

void encodeText(Node *root, string text, fstream &fp)
{
    map<char, string> charCode;
    string code;
    mapCharCode(root, 0, code, charCode);
    for (int i = 0; i < text.length(); i++)
    {
        fp << charCode[text[i]];
    }
}

void flattenTree(Node *root, int seq, fstream &fp)
{
    if (seq == 1)
    {
        if (root->symbol == '0')
        {
            fp << 1;
        }
        else
        {
            fp << 0;
        }
        if (root->left)
        {
            flattenTree(root->left, 1, fp);
        }
        if (root->right)
        {
            flattenTree(root->right, 1, fp);
        }
    }
    if (seq == 2)
    {
        if (root->left)
        {
            flattenTree(root->left, 2, fp);
        }
        if (root->right)
        {
            flattenTree(root->right, 2, fp);
        }
        if (root->symbol != '0')
        {
            fp << root->symbol;
        }
    }
}

void swap(Node **x, Node **y)
{
    Node *temp = *x;
    *x = *y;
    *y = temp;
}

Node *newNode(char symbol, int freq)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->freq = freq;
    temp->symbol = symbol;
    return temp;
}

void insert(MinHeap *minHeap, Node *top)
{
    int t = minHeap->heap_size;
    minHeap->heap_size++;

    while (t != 0 && top->freq <= minHeap->elements[(t - 1) / 2]->freq)
    {
        minHeap->elements[t] = minHeap->elements[(t - 1) / 2];
        t = (t - 1) / 2;
    }

    minHeap->elements[t] = top;
}

void minHeapify(int i, MinHeap *minHeap)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int toSwap = i;

    if (l < minHeap->heap_size && minHeap->elements[l]->freq < minHeap->elements[toSwap]->freq)
    {
        toSwap = l;
    }
    if (r < minHeap->heap_size && minHeap->elements[r]->freq < minHeap->elements[toSwap]->freq)
    {
        toSwap = r;
    }

    if (toSwap != i)
    {
        swap(&minHeap->elements[i], &minHeap->elements[toSwap]);
        minHeapify(toSwap, minHeap);
    }
}

Node *extractMin(MinHeap *minHeap)
{
    Node *min = minHeap->elements[0];
    minHeap->elements[0] = minHeap->elements[minHeap->heap_size - 1];
    minHeap->heap_size--;

    minHeapify(0, minHeap);
    return min;
}

Node *buildHuffman(int freq[][2], int count)
{
    Node *l, *r, *top;
    MinHeap *minHeap = (MinHeap *)malloc(sizeof(MinHeap));
    minHeap->elements = (Node **)malloc(count * sizeof(Node *));

    for (int i = 0; i < count; i++)
    {
        minHeap->elements[i] = newNode(freq[i][0], freq[i][1]);
    }

    minHeap->heap_size = count;
    count--;

    for (int i = (count - 1) / 2; i >= 0; i--)
    {
        minHeapify(i, minHeap);
    }

    while (minHeap->heap_size > 1)
    {
        l = extractMin(minHeap);
        r = extractMin(minHeap);

        top = newNode('0', l->freq + r->freq);
        if (l->freq >= r->freq)
        {
            top->left = l;
            top->right = r;
        }
        else
        {
            top->left = r;
            top->right = l;
        }

        insert(minHeap, top);
    }

    return extractMin(minHeap);
}

void huffmanEncoding(int freq[][2], int count, string text)
{
    Node *root = buildHuffman(freq, count);

    int arr[1000];
    fstream fout;
    fout.open("output.txt", ios::out);

    flattenTree(root, 1, fout);
    fout << endl;
    flattenTree(root, 2, fout);
    fout << endl;
    encodeText(root, text, fout);
    fout.close();
}

int main(int argc, char *argv[])
{
    fstream fin;
    string line;
    int arr[26] = {};
    int freq[26][2];
    int count = 0;

    fin.open(argv[1], ios::in);
    getline(fin, line);

    for (int i = 0; i < line.length(); i++)
    {
        int ind = line[i] - 'a';
        arr[ind] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        char letter = i + 'a';
        if (arr[i] != 0)
        {
            freq[count][0] = letter;
            freq[count][1] = arr[i];
            count++;
        }
    }

    huffmanEncoding(freq, count, line);

    fin.close();
    return 0;
}