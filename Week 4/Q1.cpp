// Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by dividing the array into two subarrays and combining these subarrays after sorting each one of them. Your program should also find number of comparisons and inversions during sorting the array.

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high, int &comp, int &inv)
{
    int i = 0, j = 0, k = low, m = mid - low + 1, n = high - mid;
    vector<int> v1(m), v2(n);

    for (int i = 0; i < m; i++)
        v1[i] = arr[low + i];
    for (int i = 0; i < n; i++)
        v2[i] = arr[mid + 1 + i];

    while (i < m && j < n)
    {
        comp++;
        if (v1[i] < v2[j])
            arr[k++] = v1[i++];
        else
        {
            inv += m - i;
            arr[k++] = v2[j++];
        }
    }

    while (i < m)
        arr[k++] = v1[i++];

    while (j < n)
        arr[k++] = v2[j++];
}

void mergeSort(vector<int> &arr, int low, int high, int &comp, int &inv)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid, comp, inv);
        mergeSort(arr, mid + 1, high, comp, inv);
        merge(arr, low, mid, high, comp, inv);
    }
}

int main()
{
    int t, n;
    cin >> t;

    do
    {
        int comp = 0, inv = 0;
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        mergeSort(v, 0, n - 1, comp, inv);

        for (int i = 0; i < n; i++)
            cout << v[i] << " ";

        cout << "\ncomparisons = " << comp << "\ninversions = " << inv << "\n";
        t--;
    } while (t != 0);

    return 0;
}