// Given a directed graph with two vertices ( source and destination). Design an algorithm and implement it using a program to find the weight of the shortest path from source to destination with exactly k edges on the path.
#include <bits/stdc++.h>
using namespace std;

int solution(unordered_map<int, vector<pair<int, int>>> &graph, int src, int dest, int k, set<int> &visited)
{
    if (src == dest)
        return 0;

    visited.insert(src);

    int min_weight = INT_MAX;

    for (auto it = graph[src].begin(); it != graph[src].end(); it++)
    {
        int node = it->first;
        int weight = it->second;

        if (visited.find(node) == visited.end())
        {
        }
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
    int n, val, src, dest, k;
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

    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "(" << graph[i][j].first << ", " << graph[i][j].second << ") ";
        }
        cout << "\n";
    }

    return 0;
}