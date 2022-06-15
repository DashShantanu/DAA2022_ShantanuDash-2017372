// Given a sequence of matrices, write an algorithm to find most efficient way to multiply these matrices together. To find the optimal solution, you need to find the order in which these matrices should be multiplied.
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &matrices, int l, int r)
{
    if (l >= r)
        return 0;

    int res = INT_MAX, temp;

    for (int k = l; k < r; k++)
    {
        int leftCost = minOperations(matrices, l, k);
        int rightCost = minOperations(matrices, k + 1, r);
        int currCost = matrices[l] * matrices[k] * matrices[r];

        temp = leftCost + rightCost + currCost;

        res = min(res, temp);
    }

    return res;
}

int main()
{
    int n, row, col;
    cin >> n;
    vector<int> matrices(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> row >> col;
        matrices[i] = row;
    }
    matrices[n] = col;

    cout << minOperations(matrices, 1, n - 1);

    return 0;
}