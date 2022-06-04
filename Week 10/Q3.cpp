// Given an unsorted array of elements, design an algorithm and implement it using a program to find whether majority element exists or not. Also find median of the array. A majority element is an element that appears more than n/2 times, where n is the size of array.
#include <bits/stdc++.h>
using namespace std;

int findMedian(unordered_map<int, int> mp)
{
    int maxCount = 0;
    for (auto it : mp)
        maxCount = max(maxCount, it.second);

    for (auto it : mp)
        if (it.second == maxCount)
            return it.first;

    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    int flag = 1;
    for (auto it : mp)
    {
        if (it.second > n / 2)
        {
            cout << "yes\n";
            flag = 0;
        }
    }
    if (flag)
        cout << "no\n";

    cout << findMedian(mp) << "\n";

    return 0;
}