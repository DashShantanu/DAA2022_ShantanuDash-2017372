// Implement selection sort and also print the total number of comparisons

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int selectionSort(vector<int> &arr)
{
    int n = arr.size(), min, count = 0;

    for (int i = 0; i < n; i++)
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

    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int comparisons = selectionSort(arr);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nComparisons = " << comparisons;

    return 0;
}