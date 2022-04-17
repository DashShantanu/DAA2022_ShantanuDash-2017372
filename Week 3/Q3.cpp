// Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

bool findDuplicate(vector<int> arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return true;
    }

    return false;
}

int main()
{
    int t, n;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        findDuplicate(v) ? cout << "YES\n" : cout << "NO\n";

        t--;
    } while (t != 0);

    return 0;
}