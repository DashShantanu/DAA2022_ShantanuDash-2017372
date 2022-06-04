// Given a long list of tasks. Each task takes specific time to accomplish it and each task has a deadline associated with it. You have to design an algorithm and implement it using a program to find maximum number of tasks that can be completed without crossing their deadlines and also find list of selected tasks.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, duration, deadline;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++)
    {
        cin >> duration;
        tasks[i].first = duration;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> deadline;
        tasks[i].second = deadline;
    }
    vector<pair<int, int>> helper = tasks;

    sort(helper.begin(), helper.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });

    vector<int> selected;
    int time = 0, count = 0, index;

    for (int i = 0; i < n; i++)
    {
        if (time + helper[i].first <= helper[i].second)
        {
            index = find(tasks.begin(), tasks.end(), helper[i]) - tasks.begin();
            selected.push_back(index + 1);
            count++;
            time += helper[i].first;
        }
    }

    cout << "Max number of tasks = " << count << "\n";
    cout << "Selected task numbers : ";
    for (auto it : selected)
        cout << it << " ";

    return 0;
}