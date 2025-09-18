#include <bits/stdc++.h>
using namespace std;

class TaskManager
{
    priority_queue<pair<int, int>> tasks;
    unordered_map<int, int> taskPriority;
    unordered_map<int, int> taskOwner;

public:
    TaskManager(vector<vector<int>> &tasks)
    {
        for (const auto &task : tasks)
        {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority)
    {
        tasks.push({priority, taskId});
        taskPriority[taskId] = priority;
        taskOwner[taskId] = userId;
    }

    void edit(int taskId, int newPriority)
    {
        tasks.push({newPriority, taskId});
        taskPriority[taskId] = newPriority;
    }

    void rmv(int taskId)
    {
        taskPriority[taskId] = -1;
    }

    int execTop()
    {
        while (!tasks.empty())
        {
            const auto task = tasks.top();
            tasks.pop();
            if (task.first == taskPriority[task.second])
            {
                taskPriority[task.second] = -1;
                return taskOwner[task.second];
            }
        }
        return -1;
    }
};

int main()
{

    vector<vector<int>> tasks = {
        {1, 101, 10},
        {2, 102, 20},
        {3, 103, 15}};

    TaskManager *taskManager = new TaskManager(tasks);

    taskManager->add(4, 104, 5);
    taskManager->edit(102, 8);
    cout << taskManager->execTop() << " "; // 3 (executes task 103)
    taskManager->rmv(101);
    taskManager->add(5, 105, 15);
    cout << taskManager->execTop() << " ";

    return 0;
}