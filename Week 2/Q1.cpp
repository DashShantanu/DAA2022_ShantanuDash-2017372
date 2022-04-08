// Given a sorted array of positive integers containing few duplicate elements, design an algorithm and implement it using a program to find whether the given key element is present in the array or not. If present, then also find the number of copies of given key.

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> v, int key)
{
    int n = v.size();

    if (binary_search(v.begin(), v.end(), key))
    {
        return (upper_bound(v.begin(), v.end(), key) - v.begin()) - (lower_bound(v.begin(), v.end(), key) - v.begin());
    }

    return 0;
}

int main()
{
    int t, n, key, ans;
    cin >> t;

    do
    {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        cin >> key;

        ans = solution(v, key);

        if (ans != 0)
            cout << key << " - " << ans << "\n";
        else
            cout << "Key not present\n";

        t--;
    } while (t != 0);

    return 0;
}