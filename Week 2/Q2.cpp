// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] == arr[k].
#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> v)
{
    int n = v.size();
    vector<int> ans;

    for (int i = 0; i < n - 2; i++)
        for (int j = i + 1; j < n - 1; j++)
            for (int k = i + 2; k < n; k++)
                if (v[i] + v[j] == v[k])
                    ans = {i, j, k};

    return ans;
}

int main()
{
    int t, n;
    vector<int> v(n), ans;
    cin >> t;

    while (t > 0)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
            cin >> v[i];

        ans = solution(v);

        if (ans.size() == 0)
            cout << "No sequence found\n";
        else
            for (int i = 0; i < 3; i++)
                cout << ans[i] << " ";

        cout << "\n";

        t--;
    }

    return 0;
}