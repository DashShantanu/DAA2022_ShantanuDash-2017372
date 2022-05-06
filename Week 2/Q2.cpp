// Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] == arr[k].
#include <bits/stdc++.h>
using namespace std;

bool twoSum(vector<int> v, int j, int k)
{
    int n = v.size(), i = 0;

    while (i < j)
    {
        if (v[i] + v[j] == v[k])
        {
            cout << i + 1 << " " << j + 1 << " " << k + 1 << endl;
            return true;
        }
        else if (v[i] + v[j] < v[k])
            i++;
        else
            j--;
    }

    return false;
}

void solution(vector<int> v)
{
    int n = v.size();
    bool flag = false;

    for (int i = n - 1; i > 1; i--)
        flag = flag || twoSum(v, i - 1, i);

    if (!flag)
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