// Q1 using Bellman Ford
#include <bits/stdc++.h>
using namespace std;

void bellmanFord(unordered_map<int, vector<pair<int, int>>> graph, int src, vector<int> &minPath)
{
    vector<int> parent(graph.size() + 1, -1);
    pair<int, int> neighbor;

    for (int k = 1; k < graph.size(); k++)
    {
        for (int i = 1; i <= graph.size(); i++)
        {
            for (int j = 0; j < graph[i].size(); j++)
            {
                neighbor = graph[i][j];
                if (minPath[i] + neighbor.second < minPath[neighbor.first])
                {
                    minPath[neighbor.first] = minPath[i] + neighbor.second;
                    parent[neighbor.first] = i;
                }
            }
        }
    }

    int dest;
    for (int i = 1; i < graph.size() + 2; i++)
    {
        if (parent[i] != -1)
        {
            dest = i;
            while (parent[dest] != -1)
            {
                cout << dest << " ";
                dest = parent[dest];
            }
        }
        cout << src << ": " << minPath[i] << endl;
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
    int n, val, src;
    cin >> n;
    vector<int> minPath(n + 1, INT_MAX);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val;
            if (val != 0)
                graph[i].push_back({j, val});
        }
    }

    cin >> src;
    minPath[src] = 0;

    bellmanFord(graph, src, minPath);

    return 0;
}