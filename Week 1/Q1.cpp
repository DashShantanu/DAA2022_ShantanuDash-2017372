// Given an array of non-negative integers, design a linear algorithm and implement it using a program to find whether given key element is present in the array or not. Also, find total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input)

#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> arr, int key, int &count)
{
    for (int i = 0; i < arr.size(); i++)
    {
        count++;
        if (key == arr[i])
            return true;
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

        ans = linearSearch(v, key, count);

        if (ans)
            cout << "Present " << count << "\n";
        else
            cout << "Not Present " << count << "\n";

        t--;
    } while (t != 0);

    return 0;
}