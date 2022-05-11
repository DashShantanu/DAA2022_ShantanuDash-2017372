// Given a directed graph, design an algorithm and implement it using a program to find whether cycle exists in the graph or not.
#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>> graph, int src, set<int> &visited)
{
    visited.insert(src);

    for (int i = 0; i < graph[src].size(); i++)
    {
        if (visited.count(graph[src][i]) == 1)
            return true;
        else
            return dfs(graph, graph[src][i], visited);
    }

    return false;
}

int main()
{
    unordered_map<int, vector<int>> graph;
    int n, val;
    cin >> n;
    set<int> visited;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val;
            if (val == 1)
            {
                graph[i].push_back(j);
            }
        }
    }

    if (dfs(graph, 1, visited))
        cout << "Yes Cycle exists\n";
    else
        cout << "No Cycle exists\n";

    return 0;
}