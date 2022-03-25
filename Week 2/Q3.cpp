// Implement insertion sort and also print the total number of comparisons

#include <bits/stdc++.h>
using namespace std;

int insertionSort(vector<int> &arr)
{
    int n = arr.size(), count = 1;
    int i = 1, j, temp;

    while (i < n)
    {
        j = i - 1;
        temp = arr[i];

        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }

        arr[j + 1] = temp;
        i++;
    }

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons = insertionSort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons = " << comparisons;

    return 0;
}