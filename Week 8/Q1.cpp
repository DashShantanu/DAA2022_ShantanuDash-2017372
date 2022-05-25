// Assume that a project of road construction to connect some cities is given to your friend. Map of these cities and roads which will connect them (after construction) is provided to him in the form of a graph. Certain amount of rupees is associated with construction of each road. Your friend has to calculate the minimum budget required for this project. The budget should be designed in such a way that the cost of connecting the cities should be minimum and number of roads required to connect all the cities should be minimum (if there are N cities then only N-1 roads need to be constructed). He asks you for help. Now, you have to help your friend by designing an algorithm which will find minimum cost required to connect these cities. (use Prim's algorithm)
#include <bits/stdc++.h>
using namespace std;

void prims(unordered_map<int, vector<pair<int, int>>> &graph, vector<int> &weight, set<int> &setMST)
{
    int minVal, minIndex;
    pair<int, int> neighbor;

    while (setMST.size() != graph.size())
    {
        minVal = INT_MAX;
        for (int i = 1; i < weight.size(); i++)
        {
            if (setMST.find(i) == setMST.end() && weight[i] < minVal)
            {
                minVal = weight[i];
                minIndex = i;
            }
        }
        setMST.insert(minIndex);

        for (int i = 0; i < graph[minIndex].size(); i++)
        {
            neighbor = graph[minIndex][i];
            if (setMST.find(neighbor.first) == setMST.end() && weight[neighbor.first] > neighbor.second)
            {
                weight[neighbor.first] = neighbor.second;
            }
        }
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
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

    set<int> setMST;
    vector<int> weight(n + 1, INT_MAX);
    weight[1] = 0;

    prims(graph, weight, setMST);

    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        if (setMST.find(i) != setMST.end())
            total += weight[i];
    }

    cout << total << "\n";

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