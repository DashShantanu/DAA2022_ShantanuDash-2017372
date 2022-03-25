// Implement bubble sort and also print the ntotal number of comparisons

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSort(vector<int> &arr)
{
    int n = arr.size(), count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            count++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
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

    int comparisons = bubbleSort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons = " << comparisons;

    return 0;
}