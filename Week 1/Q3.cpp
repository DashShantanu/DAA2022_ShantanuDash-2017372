// Given an already sorted array of positive integers, design an algorithm and implement it using a program to find whether a given key element is present in the sorted array or not. For an array arr[n], search at the indexes arr[0], arr[2], arr[4],.....,arr[2k] and so on. Once the interval (arr[2k] < key < arr[ 2k+1] ) is found, perform a linear search operation from the index 2k to find the element key. (Complexity < O(n), where n is the number of elements need to be scanned for searching): Jump Search

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> arr, int start, int key, int &count)
{
    for (int i = start; i < arr.size(); i++)
    {
        count++;
        if (key == arr[i])
            return true;
    }
    return false;
}

bool jumpSearch(vector<int> v, int key, int &count)
{
    int n = v.size();

    for (int i = 0; i < n; i += 2)
    {
        count++;
        if (key == v[i])
            return true;
        else if (key < v[i])
            return linearSearch(v, i - 2, key, count);
        else if (key > v[i] && i == n - 2)
            return linearSearch(v, i + 1, key, count);
    }

    return false;
}

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

        ans = jumpSearch(v, key, count);

        if (ans)
            cout << "Present " << count << "\n";
        else
            cout << "Not Present " << count << "\n";

        t--;
    } while (t != 0);

    return 0;
}