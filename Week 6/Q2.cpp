// Given a graph, design an algorithm and implement it using a program to find if a graph is bipartite or not. (Hint: use BFS)
#include <bits/stdc++.h>
using namespace std;

void checkBipartite(unordered_map<int, vector<int>> graph, int source)
{
    queue<int> q;
    vector<int> visited(graph.size(), 0);
    q.push(source);
    visited[source] = 1;

    vector<int> color(graph.size());
    int neighbor;
    color[source] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        for (int i = 0; i < graph[curr].size(); i++)
        {
            neighbor = graph[curr][i];

            if (visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
                color[neighbor] = 1 - color[curr];
                q.push(neighbor);
            }
            else if (color[neighbor] == color[curr])
            {
                cout << "Not Bipartite\n";
                return;
            }
        }
    }
    cout << "Yes Bipartite\n";
}

int main()
{
    unordered_map<int, vector<int>> graph;
    int n, val, src, dest;
    cin >> n;
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

    checkBipartite(graph, 1);

    return 0;
}