#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int course, vector<vector<int>> &adjList, vector<bool> &visited, vector<bool> &recursionStack)
{
    visited[course] = true;
    recursionStack[course] = true;

    for (int &nexCourse : adjList[course])
    {
        if (!visited[nexCourse])
        {
            if (hasCycle(nexCourse, adjList, visited, recursionStack))
                return true;
        }
        else if (recursionStack[nexCourse])
            return true;
    }
    recursionStack[course] = false;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> adjList(numCourses);

    for (auto &prerequisite : prerequisites)
    {
        int course = prerequisite[0];
        int prerequisiteCourse = prerequisite[1];
        adjList[prerequisiteCourse].push_back(course);
    }

    vector<bool> visited(numCourses);
    vector<bool> recursionStack(numCourses);

    for (int i = 0; i < numCourses; i++)
    {
        if (!visited[i] && hasCycle(i, adjList, visited, recursionStack))
            return false;
    }
    return true;
}

int main()
{

    int numCourses = 2;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}};

    cout << (canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}