#include <bits/stdc++.h>
using namespace std;

int find(int v, vector<pair<int, int>> dsuf)
{
    if (dsuf[v].first == -1)
        return v;

    return dsuf[v].first = find(dsuf[v].first, dsuf); // path compression
}

void unionOP(int fromP, int toP, vector<pair<int, int>> &dsuf)
{
    // UNION by rank
    if (dsuf[fromP].second > dsuf[toP].second)
        dsuf[toP].first = fromP;
    else if (dsuf[fromP].second < dsuf[toP].second)
        dsuf[fromP].first = toP;
    else
    {
        dsuf[fromP].first = toP;
        dsuf[toP].second++; // Increase rank of parent
    }
}

bool isCyclic(vector<pair<int, int>> edges, vector<pair<int, int>> &dsuf)
{
    for (auto it : edges)
    {
        // finding absolute parent
        int fromP = find(it.first, dsuf);
        int toP = find(it.second, dsuf);

        if (fromP == toP)
            return true;

        // UNION operation
        unionOP(fromP, toP, dsuf); // union of 2 disjoint sets
    }

    return false;
}

int main()
{
    vector<pair<int, int>> edges;
    int n, from, to;
    cin >> n;

    for (int i = 1; i <= n + 1; i++)
    {
        cin >> from >> to;
        edges.push_back({from, to});
    }

    vector<pair<int, int>> dsuf(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        dsuf[i].first = -1;
        dsuf[i].second = 0;
    }

    if (isCyclic(edges, dsuf))
        cout << "YES\n";
    else
        cout << "NO\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}