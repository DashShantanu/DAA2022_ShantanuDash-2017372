// Given a graph, Design an algorithm and implement it using a program to implement Floyd- Warshall all pair shortest path algorithm.
#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>> &graph, vector<vector<int>> &result)
{
    int n = graph.size();
    // Find all pair shortest path by trying out all possible paths
    // Trying all intermediate nodes
    for (int k = 0; k < n; k++)
    {
        // Trying for all the possible starting positions
        for (int i = 0; i < n; i++)
        {
            // Trying for all possible ending positions
            for (int j = 0; j < n; j++)
            {
                if (result[i][k] == INT_MAX || result[k][j] == INT_MAX) // Skip if k is unreachable from i or j is unreachable from k
                    continue;
                else // check if new distance is shorter via vertex k
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    string s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> s;
            if (s == "INF")
            {
                graph[i][j] = INT_MAX;
            }
            else
            {
                graph[i][j] = stoi(s);
            }
        }
    }

    vector<vector<int>> result = graph;

    floydWarshall(graph, result);

    cout << "Shortest Distance Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (result[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << result[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}