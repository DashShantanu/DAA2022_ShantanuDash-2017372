// II.	Given a knapsack of maximum capacity w. N items are provided, each having its own value and weight. You have to design an algorithm and implement it using a program to find the list of the selected items such that the final selected content has weight w and has maximum value. You can take fractions of items,i.e. the items can be broken into smaller pieces so that you have to carry only a fraction xi of item i, where 0<= xi <= 1.
#include <bits/stdc++.h>
using namespace std;

void fractionalKnapsack(vector<pair<int, int>> items, vector<pair<int, double>> fractions, int maxWeight)
{
    int i = 0, weight;
    double maxValue = 0;
    vector<pair<int, int>> result;

    sort(fractions.begin(), fractions.end(), [](pair<int, double> &a, pair<int, double> &b)
         { return a.second > b.second; });

    while (maxWeight > 0 && i < fractions.size())
    {
        weight = items[fractions[i].first].first;
        if (maxWeight - weight >= 0)
        {
            result.push_back({fractions[i].first + 1, weight});
            maxValue += items[fractions[i].first].second;
            maxWeight -= weight;
        }
        else
        {
            result.push_back({fractions[i].first + 1, maxWeight});
            maxValue += (items[fractions[i].first].second) * ((double)maxWeight / weight);
            maxWeight = 0;
        }
        i++;
    }

    cout << "Maximum value : " << maxValue << "\n";
    cout << "items - weight\n";
    for (auto it : result)
        cout << it.first << " - " << it.second << "\n";
}

int main()
{
    int n, maxWeight;
    cin >> n;
    vector<pair<int, int>> items(n);
    vector<pair<int, double>> fractions(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].second;
        fractions[i].first = i;
        fractions[i].second = (double)items[i].second / items[i].first;
    }
    cin >> maxWeight;

    fractionalKnapsack(items, fractions, maxWeight);

    return 0;
}