#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int l = triangle.size();
    vector<int> total(l);

    for (int i = 0; i < triangle[l - 1].size(); i++)
    {
        total[i] = triangle[l - 1][i];
    }

    for (int i = l - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
            total[j] = triangle[i][j] + min(total[j], total[j + 1]);
    }

    return total[0];
}

int main()
{

    vector<vector<int>> triangle = {
        {2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}