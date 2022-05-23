// After end term examination, Akshay wants to party with his friends. All his friends are living as paying guest and it has been decided to first gather at Akshay’s house and then move towards party location. The problem is that no one knows the exact address of his house in the city. Akshay as a computer science wizard knows how to apply his theory subjects in his real life and came up with an amazing idea to help his friends. He draws a graph by looking in to location of his house and his friends’ location (as a node in the graph) on a map. He wishes to find out shortest distance and path covering that distance from each of his friend’s location to his house and then whatsapp them this path so that they can reach his house in minimum time. Akshay has developed the program that implements Dijkstra’s algorithm but not sure about correctness of results. Can you also implement the same algorithm and verify the correctness of Akshay’s results? (Hint: Print shortest path and distance from friends’ location to Akshay’s house)
#include <bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<int, vector<pair<int, int>>> graph, int src, vector<int> &minPath, set<int> &visited)
{
    vector<int> parent(graph.size() + 1, -1);
    int temp = src;
    pair<int, int> neighbor;

    while (visited.size() != graph.size())
    {
        for (int i = 1; i <= graph.size(); i++)
        {
            if (minPath[i] < INT_MAX && visited.find(i) == visited.end())
            {
                temp = i;
            }
        }
        visited.insert(temp);

        for (int i = 0; i < graph[temp].size(); i++)
        {
            neighbor = graph[temp][i];
            if (minPath[neighbor.first] > minPath[temp] + neighbor.second)
            {
                minPath[neighbor.first] = minPath[temp] + neighbor.second;
                parent[neighbor.first] = temp;
            }
        }
    }

    // Print shortest graph path
    // for (int i = 1; i <= graph.size() + 1; i++)
    //     cout << parent[i] << " ";
    // cout << "\n";

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
    set<int> visited;

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

    dijkstra(graph, src, minPath, visited);

    return 0;
}