// Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it. (Time Complexity = O(n)) (Hint: Use counting sort)

#include <bits/stdc++.h>
using namespace std;

void maxOccurence(vector<char> &arr)
{
    int n = arr.size(), i, j, count = 0;
    vector<int> v(26);

    for (i = 0; i < n; i++)
        v[arr[i] - 'a']++;

    for (i = 0; i < 26; i++)
    {
        if (v[i] > count)
        {
            count = v[i];
            j = i;
        }
    }

    if (count > 1)
        cout << (char)(j + 'a') << " - " << count << "\n";
    else
        cout << "No Duplicates Present\n";
}

int main()
{
    int t, n;
    cin >> t;

    do
    {
        cin >> n;
        vector<char> v(n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        maxOccurence(v);

        t--;
    } while (t != 0);

    return 0;
}