// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] == arr[k].
#include <bits/stdc++.h>
using namespace std;

void solution(vector<int> v)
{
    int n = v.size();

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = j + 1; k < n; k++)
                if (v[i] + v[j] == v[k])
                {
                    cout << i + 1 << ", " << j + 1 << ", " << k + 1 << "\n";
                    return;
                }

    cout << "No sequence found\n";
}

int main()
{
    int t, n;
    cin >> t;

    while (t > 0)
    {
        cin >> n;
        vector<int> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        solution(v);

        t--;
    }

    return 0;
}