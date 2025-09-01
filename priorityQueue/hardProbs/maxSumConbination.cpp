#include <bits/stdc++.h>
using namespace std;

// soln for https://www.interviewbit.com/problems/maximum-sum-combinations/

vector<int> solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>> indicesSet;
    maxHeap.push({A[0] + B[0], {0, 0}});
    indicesSet.insert({0, 0});

    vector<int> result;

    while (result.size() < C)
    {
        auto top = maxHeap.top();
        maxHeap.pop();

        int sum = top.first;
        int i = top.second.first;
        int j = top.second.second;
        result.push_back(sum);
        if (i + 1 < n && indicesSet.find({i + 1, j}) == indicesSet.end())
        {
            maxHeap.push({A[i + 1] + B[j], {i + 1, j}});
            indicesSet.insert({i + 1, j});
        }
        if (j + 1 < n && indicesSet.find({i, j + 1}) == indicesSet.end())
        {
            maxHeap.push({A[i] + B[j + 1], {i, j + 1}});
            indicesSet.insert({i, j + 1});
        }
    }

    return result;
}

int main()
{
    vector<int> A = {1, 4, 2, 3};
    vector<int> B = {2, 5, 1, 6};
    int C = 4;

    vector<int> result = solve(A, B, C);
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}