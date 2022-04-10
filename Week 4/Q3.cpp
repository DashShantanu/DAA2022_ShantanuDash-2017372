// Given an unsorted array of integers, design an algorithm and implement it using a program to find Kth smallest or largest element in the array.

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
    int pivot = arr[low], i = low, j = high;

    while (i < j)
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
            swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);

    return j;
}

int partition_r(vector<int> &arr, int low, int high)
{
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[low]);

    return partition(arr, low, high);
}

int quickSelect(vector<int> &arr, int low, int high, int k)
{
    if (low < high)
    {
        int j = partition_r(arr, low, high);
        if (j + 1 == k)
            return arr[j];
        else if (j + 1 > k)
            return quickSelect(arr, low, j, k);
        else
            return quickSelect(arr, j + 1, high, k);
    }
    else
        return -1;
}

int main()
{
    int t, n, k;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cin >> k;

        cout << quickSelect(v, 0, n - 1, n - k + 1) << "\n";

        t--;
    } while (t != 0);

    return 0;
}