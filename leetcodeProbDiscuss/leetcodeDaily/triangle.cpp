#include <bits/stdc++.h>
using namespace std;

int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> total(n);
    int l = n - 1;

    for (int i = 0; i < triangle[l].size(); i++)
    {
        total[i] = triangle[l][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i + 1].size() - 1; j++)
        {
            total[j] = triangle[i][j] + min(total[j], total[j + 1]);
        }
    }
    return total[0];
}

int main()
{

    vector<vector<int>> triangle = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}};

    cout << minimumTotal(triangle) << endl;

    return 0;
}