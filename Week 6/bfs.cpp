#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> graph, int source)
{
    queue<int> q;
    vector<int> visited(graph.size(), 0);
    q.push(source);
    visited[source] = 1;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << " ";
        for (int i = 0; i < graph[curr].size(); i++)
        {
            if (visited[graph[curr][i]] == 0)
            {
                q.push(graph[curr][i]);
                visited[graph[curr][i]] = 1;
            }
        }
    }
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

    bfs(graph, 1);

    return 0;
}