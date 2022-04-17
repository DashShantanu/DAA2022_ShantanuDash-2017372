// Implement selection sort and also print the total number of comparisons

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(vector<int> &arr, int &count)
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
    }
}

int main()
{
    int t, n;
    cin >> t;

    while (t > 0)
    {
        int count = 0;
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        selectionSort(arr, count);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";

        cout << "\ncomparisons = " << count << "\nswaps = " << n - 1 << "\n";

        t--;
    }

    return 0;
}