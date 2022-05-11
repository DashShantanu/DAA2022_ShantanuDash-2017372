// Given a (directed/undirected) graph, design an algorithm and implement it using a program to find if a path exists between two given vertices or not. (Hint: use DFS)
#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>> graph, int src, int dest, vector<int> &visited)
{
    if (src == dest)
        return true;

    visited[src] = 1;

    for (int i = 0; i < graph[src].size(); i++)
    {
        if (visited[graph[src][i]] == 0)
        {
            if (dfs(graph, graph[src][i], dest, visited))
                return true;
        }
    }

    return false;
}

int main()
{
    unordered_map<int, vector<int>> graph;
    int n, val, src, dest;
    cin >> n;
    vector<int> visited(n + 1, 0);
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

    cin >> src >> dest;

    cout << dfs(graph, src, dest, visited) << "\n";

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}