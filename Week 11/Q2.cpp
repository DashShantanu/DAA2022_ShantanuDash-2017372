// Given a set of available types of coins. Let suppose you have infinite supply of each type of coin. For a given value N, you have to Design an algorithm and implement it using a program to find number of ways in which these coins can be added to make sum value equals to N.
#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int> coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1));

    // Fill 1st row with zero as no amount can be formed without any coin
    int i, j;
    for (i = 0; i < amount + 1; i++)
        dp[0][i] = 0;
    // Fill first col by 1 as 0 can always be formed
    for (i = 0; i < n + 1; i++)
        dp[i][0] = 1;

    // Fill dp table
    for (i = 1; i < n + 1; i++)
    {
        for (j = 1; j < amount + 1; j++)
        {
            if (j >= coins[i - 1])
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][amount];
}

int main()
{
    int n, amount;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    cin >> amount;

    cout << coinChange(coins, amount);

    return 0;
}