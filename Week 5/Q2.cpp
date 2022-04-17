// Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element. (Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

void twoSum(vector<int> &arr, int key)
{
    int n = arr.size(), i = 0, j = n - 1;

    sort(arr.begin(), arr.end());

    while (i < j)
    {
        if (arr[i] + arr[j] == key)
        {
            cout << arr[i] << " " << arr[j] << "\n";
            return;
        }
        else if (arr[i] + arr[j] > key)
            j--;
        else
            i++;
    }

    cout << "No Such Elements Exist";
}

int main()
{
    int t, n, key;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cin >> key;

        twoSum(v, key);

        t--;
    } while (t != 0);

    return 0;
}