#include <bits/stdc++.h>
using namespace std;

vector<int> getBiggestThree(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    set<int> st;

    for (int r = 0; r < m; r++)
    {
        for (int c = 0; c < n; c++)
        {

            // radius 0
            st.insert(grid[r][c]);

            for (int k = 1;; k++)
            {

                if (r + 2 * k >= m || c - k < 0 || c + k >= n)
                    break;

                int sum = 0;
                int x = r, y = c;

                // top -> right
                for (int i = 0; i < k; i++)
                    sum += grid[x + i][y + i];

                // right -> bottom
                for (int i = 0; i < k; i++)
                    sum += grid[x + k + i][y + k - i];

                // bottom -> left
                for (int i = 0; i < k; i++)
                    sum += grid[x + 2 * k - i][y - i];

                // left -> top
                for (int i = 0; i < k; i++)
                    sum += grid[x + k - i][y - k + i];

                st.insert(sum);
            }
        }
    }

    vector<int> res;
    auto it = st.rbegin();

    for (int i = 0; i < 3 && it != st.rend(); i++, it++)
        res.push_back(*it);

    return res;
}

// another solution

void addToMaxThree(vector<int> &maxThree, int num)
{

    if (maxThree[0] == num || maxThree[1] == num || maxThree[2] == num)
        return;

    sort(maxThree.begin(), maxThree.end());

    if (maxThree[0] < num)
        maxThree[0] = num;
}

int getSum(vector<vector<int>> &grid, int i, int j, int length)
{

    if (length == 0)
        return grid[i][j];

    int sum = 0;

    // edge ab
    for (int it = 0; it <= length; it++)
        sum += grid[i + it][j + it];

    // edge ad
    for (int it = 1; it <= length; it++)
        sum += grid[i + it][j - it];

    // edge dc
    for (int it = 1; it <= length; it++)
        sum += grid[i + length + it][j - length + it];

    // edge bc
    for (int it = 1; it < length; it++)
        sum += grid[i + length + it][j + length - it];

    return sum;
}

void searchBigThree(vector<vector<int>> &grid, vector<int> &maxThree, int length)
{

    int end = grid.size() - (length == 0 ? 0 : 2 * length);
    int end1 = grid[0].size() - length;

    for (int start = 0; start < end; start++)
    {
        for (int start1 = length; start1 < end1; start1++)
        {

            if (start + start1 >= length)
            {
                addToMaxThree(maxThree,
                              getSum(grid, start, start1, length));
            }
        }
    }
}

vector<int> getBiggestThreeI(vector<vector<int>> &grid)
{

    int end = min(grid.size(), grid[0].size());
    vector<int> maxThree = {0, 0, 0};

    for (int length = 0; length < end; length++)
        searchBigThree(grid, maxThree, length);

    sort(maxThree.begin(), maxThree.end());

    if (maxThree[0] == 0)
    {
        if (maxThree[1] == 0)
            return {maxThree[2]};
        return {maxThree[2], maxThree[1]};
    }

    reverse(maxThree.begin(), maxThree.end());

    return maxThree;
}

int main()
{

    vector<vector<int>> grid = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    vector<int> ans = getBiggestThreeI(grid);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}