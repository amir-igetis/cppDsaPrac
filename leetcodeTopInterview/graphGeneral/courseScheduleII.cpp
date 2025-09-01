#include <bits/stdc++.h>
using namespace std;

// bfs kahn's algo

vector<int> findOrderI(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    vector<int> inDegree(numCourses, 0);

    for (auto &pre : prerequisites)
    {
        int course = pre[0];
        int preCourse = pre[1];
        adjList[preCourse].push_back(course);
        inDegree[course]++;
    }

    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        order.push_back(curr);

        for (int next : adjList[curr])
        {
            inDegree[next]--;

            if (inDegree[next] == 0)
                q.push(next);
        }
    }

    if ((int)order.size() == numCourses)
        return order;

    else
        return {};
}

// dfs topo sort

bool dfs(int node, vector<vector<int>> &adjList, vector<int> &visisted, vector<int> &order)
{
    if (visisted[node] == 1)
        return false;

    if (visisted[node] == 2)
        return true;

    visisted[node] = 1;
    for (int next : adjList[node])
    {
        if (!dfs(next, adjList, visisted, order))
            return false;
    }

    visisted[node] = 2;
    order.push_back(node);
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);
    for (auto &pre : prerequisites)
    {
        // adjList[pre[1]].push_back(pre[0]);

        int course = pre[0];
        int prerequisiteCourse = pre[1];
        adjList[prerequisiteCourse].push_back(course);
    }

    vector<int> visisted(numCourses, 0);
    vector<int> order;

    for (int i = 0; i < numCourses; i++)
    {
        if (visisted[i] == 0)
        {
            if (!dfs(i, adjList, visisted, order))
                return {};
        }
    }

    reverse(order.begin(), order.end());
    return order;
}

int main()
{

    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    vector<int> ans = findOrderI(numCourses, prerequisites);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}