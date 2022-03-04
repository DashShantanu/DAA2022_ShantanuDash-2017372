#include <bits/stdc++.h>
using namespace std;

int searchArr(vector<int> arr, int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
        if (key == arr[i])
        {
            cout << "Comparisons = " << count << "\n";
            return i;
        }
    }

    cout << "Comparisons = " << count << "\n";
    return -1;
}

int main()
{
    vector<int> arr;
    int n, val, key;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }

    cin >> key;

    cout << searchArr(arr, n, key);

    return 0;
}