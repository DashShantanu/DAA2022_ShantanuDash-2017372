// Assume that same road construction project is given to another person. The amount he will earn from this project is directly proportional to the budget of the project. This person is greedy, so he decided to maximize the budget by constructing those roads who have highest construction cost. Design an algorithm and implement it using a program to find the maximum budget required for the project.
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dst, weight;
};

int comparator(Edge &a, Edge &b)
{
    return a.weight > b.weight;
}

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

void kruskals(unordered_map<int, vector<pair<int, int>>> &graph, vector<Edge> &edges, vector<pair<int, int>> &dsuf, vector<Edge> &mst)
{
    sort(edges.begin(), edges.end(), comparator);

    int i = 0, j = 0;
    while (i < graph.size() - 1 && j < edges.size())
    {
        // finding absolute parent
        int fromP = find(edges[j].src, dsuf);
        int toP = find(edges[j].dst, dsuf);

        if (fromP == toP)
        {
            j++;
            continue;
        }

        unionOP(fromP, toP, dsuf);
        mst.push_back(edges[j]);
        i++;
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
    vector<Edge> mst;
    int n, val;
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

    vector<Edge> edges;
    Edge temp;
    for (int i = 1; i <= graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            temp.src = i;
            temp.dst = graph[i][j].first;
            temp.weight = graph[i][j].second;
            edges.push_back(temp);
        }
    }

    vector<pair<int, int>> dsuf(n + 1);
    for (int i = 0; i < n + 1; i++)
    {
        dsuf[i].first = -1;
        dsuf[i].second = 0;
    }

    kruskals(graph, edges, dsuf, mst);

    int total = 0;
    for (auto it : mst)
    {
        total += it.weight;
    }
    cout << total << "\n";

    return 0;
}