// Given an array of non-negative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.

#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> v, int key)
{
    unordered_map<int, int> mp;
    int n = v.size(), count = 0;

    for (int i = 0; i < n; i++)
        mp[v[i]]++;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(key + v[i]) != mp.end())
            count++;
    }

    (count > 0) ? cout << count << "\n" : cout << "Key not present\n";
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

        solution(v, key);

        t--;
    } while (t != 0);

    return 0;
}