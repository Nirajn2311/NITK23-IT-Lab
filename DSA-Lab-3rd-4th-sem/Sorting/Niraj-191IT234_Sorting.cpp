#include <bits/stdc++.h>

using namespace std;

void insertionSort(int arr[], int size, int *comp, int *exch)
{
    int j, t;
    *comp = 0;
    *exch = 0;
    for (int i = 1; i < size; i++)
    {
        j = i - 1;
        t = arr[i];
        while (j > -1 && t < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
            (*exch)++;
        }
        (*comp) += i - j;
        (*exch)++;
        arr[j + 1] = t;
    }
}

void bubbleSort(int arr[], int size, int *comp, int *exch)
{
    int t;
    *comp = 0;
    *exch = 0;
    for (int i = 0, j; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                (*exch)++;
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
            (*comp)++;
        }
    }
}

void selectionSort(int arr[], int size, int *comp, int *exch)
{
    int t, num;
    *comp = 0;
    *exch = 0;
    for (int j, i = 0; i < size - 1; i++)
    {
        for (j = i + 1, t = i; j < size; j++)
        {
            if (arr[j] < arr[t])
            {
                t = j;
            }
            (*comp)++;
        }
        if (i != t)
        {
            num = arr[t];
            arr[t] = arr[i];
            arr[i] = num;
            (*exch)++;
        }
    }
}

int main()
{
    int size = 2, comp, exch, temp;
    ofstream comp_file("comp.txt");
    ofstream exch_file("exch.txt");
    for (int i = 0; i < 512; i++)
    {
        int bubble_arr[size], selection_arr[size], insertion_arr[size];
        for (int j = 0; j < size; j++)
        {
            temp = rand() % 5000;
            bubble_arr[j] = selection_arr[j] = insertion_arr[j] = temp;
        }
        bubbleSort(bubble_arr, size, &comp, &exch);
        comp_file << comp << " ";
        exch_file << exch << " ";
        selectionSort(selection_arr, size, &comp, &exch);
        comp_file << comp << " ";
        exch_file << exch << " ";
        insertionSort(insertion_arr, size, &comp, &exch);
        comp_file << comp << "\n";
        exch_file << exch << "\n";
        size += 2;
    }
    comp_file.close();
    exch_file.close();
    return 0;
}