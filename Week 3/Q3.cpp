// Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not. (use sorting) (Time Complexity = O(n log n))

#include <bits/stdc++.h>
using namespace std;

bool findDuplicate(vector<int> arr)
{
    map<int, int> mp;

    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(arr[i]) == mp.end())
            mp[arr[i]]++;
        else
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