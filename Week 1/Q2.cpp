// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(nlogn), where n is the size of input).

#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int i, int j, int key, int &count)
{
    int mid;
    while (i <= j)
    {
        mid = (i + j) / 2;
        count++;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            j = mid - 1;
        else
            i = mid + 1;
    }
    return -1;
}

// int binarySearch(vector<int> arr, int i, int j, int key, int &count)
// {
//     if (i > j)
//     {
//         return -1;
//     }

//     int mid = (i + j) / 2;
//     count++;

//     if (arr[mid] == key)
//         return mid;
//     else if (key > arr[mid])
//         return binarySearch(arr, mid + 1, j, key, count);
//     else
//         return binarySearch(arr, i, mid - 1, key, count);
// }

int main()
{
    int t, n, key, ans, count;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);
        count = 0;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cin >> key;

        ans = binarySearch(v, 0, n - 1, key, count);

        if (ans)
            cout << "Present " << count << "\n";
        else
            cout << "Not Present " << count << "\n";

        t--;
    } while (t != 0);

    return 0;
}