// #include <bits/stdc++.h>

// using namespace std;

// void swap(int *x, int *y)
// {
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// class BinaryHeap
// {
//     int elements[1000];
//     int heap_size = 0;

// public:
//     int parent(int node);
//     int left(int node);
//     int right(int node);
//     void resetSize();

//     void maximum();
//     void insert(int num);
//     void extract_max();
//     void build_heap(int i);

//     void disp()
//     {
//         for (int i = 0; i < heap_size; i++)
//         {
//             cout << elements[i] << " ";
//         }
//         cout << endl;
//     }
// };

// int BinaryHeap::parent(int node)
// {
//     return (node - 1) / 2;
// }

// int BinaryHeap::left(int node)
// {
//     return 2 * node + 1;
// }

// int BinaryHeap::right(int node)
// {
//     return 2 * node + 2;
// }

// void BinaryHeap::resetSize()
// {
//     heap_size = 0;
// }

// void BinaryHeap::maximum()
// {
//     cout << elements[0] << endl;
// }

// void BinaryHeap::insert(int num)
// {
//     cout << "INSERTED - " << num << endl;
//     if (heap_size == 1000)
//     {
//         cout << " HEAP FULL!!" << endl;
//         return;
//     }

//     elements[heap_size] = num;
//     int t = heap_size;

//     while (t != 0 && elements[parent(t)] <= elements[t])
//     {
//         swap(elements[t], elements[parent(t)]);
//         t = parent(t);
//     }

//     heap_size++;
// }

// void BinaryHeap::extract_max()
// {
//     if (heap_size == 0)
//     {
//         cout << "HEAP EMPTY!!" << endl;
//         return;
//     }

//     cout << elements[0] << endl;
//     elements[0] = elements[heap_size - 1];
//     heap_size--;

//     build_heap(0);
// }

// void BinaryHeap::build_heap(int i)
// {
//     int l = left(i);
//     int r = right(i);
//     int toSwap = i;

//     if (l < heap_size && elements[l] > elements[toSwap])
//     {
//         toSwap = l;
//     }
//     if (r < heap_size && elements[r] > elements[toSwap])
//     {
//         toSwap = r;
//     }

//     if (toSwap != i)
//     {
//         swap(elements[toSwap], elements[i]);
//         build_heap(toSwap);
//     }
// }

// int main(int argc, char *argv[])
// {
//     fstream fp;
//     string line;

//     fp.open(argv[1], ios::in);
//     getline(fp, line);
//     int no_of_l = stoi(line);

//     BinaryHeap heap;
//     for (int i = 0; i < no_of_l; i++)
//     {
//         getline(fp, line);
//         switch (line[0])
//         {
//         case '0':
//         {
//             heap.maximum();
//             break;
//         }
//         case '1':
//         {
//             string temp = "";
//             for (int i = 2; line[i] != '\0'; i++)
//             {
//                 if (line[i] == ' ')
//                 {
//                     heap.insert(stoi(temp));
//                     temp = "";
//                 }
//                 else
//                 {
//                     temp.push_back(line[i]);
//                 }
//             }
//             heap.insert(stoi(temp));
//             break;
//         }
//         case '2':
//         {
//             heap.extract_max();
//             break;
//         }
//         case '3':
//         {
//             heap.resetSize();
//             string temp = "";
//             for (int i = 2; line[i] != '\0'; i++)
//             {
//                 if (line[i] == ' ')
//                 {
//                     heap.insert(stoi(temp));
//                     temp = "";
//                 }
//                 else
//                 {
//                     temp.push_back(line[i]);
//                 }
//             }
//             heap.insert(stoi(temp));
//             break;
//         }
//         }
//     }
//     cout << endl;
//     fp.close();
//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

class BinaryHeap
{
    int elements[1000];
    int heap_size = 0;

public:
    int parent(int node);
    int left(int node);
    int right(int node);
    void resetSize();

    void maximum();
    void insert(int num);
    void extract_max();
    void build_heap(int i);

    void disp()
    {
        for (int i = 0; i < heap_size; i++)
        {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int BinaryHeap::parent(int node)
{
    return (node - 1) / 2;
}

int BinaryHeap::left(int node)
{
    return 2 * node + 1;
}

int BinaryHeap::right(int node)
{
    return 2 * node + 2;
}

void BinaryHeap::resetSize()
{
    heap_size = 0;
}

void BinaryHeap::maximum()
{
    cout << elements[0] << endl;
}

void BinaryHeap::insert(int num)
{
    if (heap_size == 1000)
    {
        cout << " HEAP FULL!!" << endl;
        return;
    }

    elements[heap_size] = num;
    int t = heap_size;

    while (t != 0 && elements[parent(t)] <= elements[t])
    {
        swap(elements[t], elements[parent(t)]);
        t = parent(t);
    }

    heap_size++;
}

void BinaryHeap::extract_max()
{
    if (heap_size == 0)
    {
        cout << "HEAP EMPTY!!" << endl;
        return;
    }

    cout << elements[0] << endl;
    elements[0] = elements[heap_size - 1];
    heap_size--;

    build_heap(0);
}

void BinaryHeap::build_heap(int i)
{
    int l = left(i);
    int r = right(i);
    int toSwap = i;

    if (l < heap_size && elements[l] > elements[toSwap])
    {
        toSwap = l;
    }
    if (r < heap_size && elements[r] > elements[toSwap])
    {
        toSwap = r;
    }

    if (toSwap != i)
    {
        swap(elements[toSwap], elements[i]);
        build_heap(toSwap);
    }
}

int main(int argc, char *argv[])
{
    fstream fp;
    string line;

    fp.open(argv[1], ios::in);
    getline(fp, line);
    int no_of_l = stoi(line);

    BinaryHeap heap;
    for (int i = 0; i < no_of_l; i++)
    {
        getline(fp, line);
        switch (line[0])
        {
        case '0':
        {
            heap.maximum();
            break;
        }
        case '1':
        {
            string temp = "";
            for (int i = 2; line[i] != '\0'; i++)
            {
                if (line[i] == ' ')
                {
                    heap.insert(stoi(temp));
                    temp = "";
                }
                else
                {
                    temp.push_back(line[i]);
                }
            }
            heap.insert(stoi(temp));
            break;
        }
        case '2':
        {
            heap.extract_max();
            break;
        }
        case '3':
        {
            heap.resetSize();
            string temp = "";
            for (int i = 2; line[i] != '\0'; i++)
            {
                if (line[i] == ' ')
                {
                    heap.insert(stoi(temp));
                    temp = "";
                }
                else
                {
                    temp.push_back(line[i]);
                }
            }
            heap.insert(stoi(temp));
            break;
        }
        }
    }
    cout << endl;
    fp.close();
    return 0;
}