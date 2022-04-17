// Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required.

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &arr, int &count, int &swaps)
{
    int n = arr.size(), min;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
        swaps++;
    }
}

int main()
{
    int t, n;
    cin >> t;

    while (t > 0)
    {
        int count = 0, swaps = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        selectionSort(arr, count, swaps);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\ncomparisons = " << count << "\nswaps = " << swaps << "\n";

        t--;
    }

    return 0;
}