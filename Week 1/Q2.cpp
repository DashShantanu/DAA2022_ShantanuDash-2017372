#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int i, int j, int key)
{
    if (i > j)
    {
        return -1;
    }

    int mid = (i + j) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key > arr[mid])
        return binarySearch(arr, mid + 1, j, key);
    else
        return binarySearch(arr, i, mid - 1, key);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int n, val, key;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }

    cin >> key;

    cout << binarySearch(arr, 0, 5, key);

    return 0;
}