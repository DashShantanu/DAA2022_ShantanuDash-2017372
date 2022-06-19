// Given a set of elements, you have to partition the set into two subsets such that the sum of elements in both subsets is same. Design an algorithm and implement it using a program to solve this problem.
#include <bits/stdc++.h>
using namespace std;

bool equalSubsets(vector<int> arr, int pos, int sum, vector<vector<int>> &mem)
{
    if (sum == 0)
        return true;
    else if (pos >= arr.size() || sum < 0)
        return false;
    if (mem[pos][sum] != -1)
        return mem[pos][sum];

    return mem[pos][sum] = equalSubsets(arr, pos + 1, sum - arr[pos], mem) || equalSubsets(arr, pos + 1, sum, mem);
}

int main()
{
    int n, sum = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    if (sum & 1)
    {
        cout << "no";
        return 0;
    }

    vector<vector<int>> mem(n + 1, vector<int>(sum / 2 + 1, -1));

    equalSubsets(arr, 0, sum / 2, mem) ? cout << "yes" : cout << "no";

    return 0;
}