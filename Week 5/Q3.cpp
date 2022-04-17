// You have been given two integer arrays of size m and n. Design an algorithm and implement it using a program to find list of elements which are common to both. (Time Complexity = O(m+n))

#include <bits/stdc++.h>
using namespace std;

void commonElements(vector<int> &arr1, vector<int> &arr2)
{
    int m = arr1.size(), n = arr2.size(), i = 0, j = 0;

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    while (i < m && j < n)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
            i++;
        else
            j++;
    }
}

int main()
{
    int m, n;

    cin >> m;
    vector<int> v1(m);
    for (int i = 0; i < m; i++)
        cin >> v1[i];
    cin >> n;
    vector<int> v2(n);
    for (int i = 0; i < n; i++)
        cin >> v2[i];

    commonElements(v1, v2);

    return 0;
}