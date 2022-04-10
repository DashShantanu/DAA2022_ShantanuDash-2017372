// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array.
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
    int i = 0, j = 0, k = low, m = mid - low + 1, n = high - mid;
    vector<int> v1(m), v2(n);

    for (int i = 0; i < m; i++)
        v1[i] = arr[low + i];
    for (int i = 0; i < n; i++)
        v2[i] = arr[mid + 1 + i];

    while (i < m && j < n)
    {
        if (v1[i] < v2[j])
            arr[k++] = v1[i++];
        else
            arr[k++] = v2[j++];
    }

    while (i < m)
        arr[k++] = v1[i++];
    while (j < n)
        arr[k++] = v2[j++];
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
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

        mergeSort(v, 0, n - 1);

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        cout << "\n";
        // cout << "\ncomparisons = " << comp << "\nswaps = " << swap << "\n";
        t--;
    } while (t != 0);

    return 0;
}