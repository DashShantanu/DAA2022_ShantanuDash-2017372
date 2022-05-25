// Given a directed graph with two vertices ( source and destination). Design an algorithm and implement it using a program to find the minimum weight of the path from source to destination with exactly k edges on the path.
#include <bits/stdc++.h>
using namespace std;

void solution(unordered_map<int, vector<pair<int, int>>> &graph, int src, int dest, int k, int &minWeight, int currTotal, set<int> &visited)
{
    if (k < 0)
        return;
    if (src == dest && k == 0)
    {
        minWeight = min(minWeight, currTotal);
        return;
    }

    visited.insert(src);

    int node, weight;

    for (auto it = graph[src].begin(); it != graph[src].end(); it++)
    {
        node = it->first;
        weight = it->second;

        if (visited.find(node) == visited.end() && currTotal + weight <= minWeight)
        {
            solution(graph, node, dest, k - 1, minWeight, currTotal + weight, visited);
        }
    }

    visited.erase(src);
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
    int n, val, src, dest, k;
    int minWeight = INT_MAX;
    set<int> visited;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val;
            if (val != 0)
                graph[i].push_back({j, val});
        }
    }

    cin >> src >> dest;
    cin >> k;

    solution(graph, src, dest, k, minWeight, 0, visited);

    if (minWeight == INT_MAX)
        cout << "No path found" << endl;
    else
        cout << minWeight << endl;

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