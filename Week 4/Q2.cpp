// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = low + (rand() % (high - low));
    int i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= arr[pivot]);
        do
        {
            j--;
        } while (arr[j] > arr[pivot]);

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[pivot], arr[j]);

    return j;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    quickSort(arr, 0, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}