// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high, int &comp, int &swaps)
{
    int pivot = arr[low], i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
            comp++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
            comp++;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
        swaps++;
    }

    swap(arr[low], arr[j]);

    return j;
}

int partition_r(vector<int> &arr, int low, int high, int &comp, int &swaps)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[low]);

    return partition(arr, low, high, comp, swaps);
}

void quickSort(vector<int> &arr, int low, int high, int &comp, int &swaps)
{
    if (low < high)
    {
        int j = partition_r(arr, low, high, comp, swaps);
        quickSort(arr, low, j, comp, swaps);
        quickSort(arr, j + 1, high, comp, swaps);
    }
}

int main()
{
    int t, n;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);
        int comp = 0, swap = 0;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        quickSort(v, 0, n, comp, swap);

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        cout << "\ncomparisons = " << comp << "\nswaps = " << swap << "\n";
        t--;
    } while (t != 0);

    return 0;
}