// Implement insertion sort and also print the total number of comparisons

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int &count, int &shift)
{
    int n = arr.size();
    int i = 1, j, temp;

    while (i < n)
    {
        j = i - 1;
        temp = arr[i];

        while (j >= 0 && arr[j] > temp)
        {
            count++;
            shift++;
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
        i++;
        shift++;
    }
}

int main()
{
    int t, n;
    cin >> t;

    while (t > 0)
    {
        int count = 0, shift = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        insertionSort(arr, count, shift);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\ncomparisons = " << count << "\nshifts = " << shift << "\n";

        t--;
    }

    return 0;
}