#include <bits/stdc++.h>
using namespace std;

int largestSubmatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int ans = 0;
    vector<int> height(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
                height[j] = 0;
            else
                height[j] += 1;
        }
        vector<int> orderHeight = height;
        sort(orderHeight.begin(), orderHeight.end());
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, orderHeight[j] * (n - j));
        }
    }
    return ans;
}

int main()
{

    vector<vector<int>> matrix = {{0, 0, 1}, {1, 1, 1}, {1, 0, 1}};
    //        output = 4;

    cout << largestSubmatrix(matrix) << endl;

    return 0;
}