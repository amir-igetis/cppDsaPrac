#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &heights)
{
    stack<int> st;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++)
    {
        int currHeight = (i == n) ? 0 : heights[i];
        while (!st.empty() && currHeight < heights[st.top()])
        {
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(vector<vector<char>> &matrix)
{

    if (matrix.empty())
        return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    vector<int> heights(cols, 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        maxArea = max(maxArea, helper(heights));
    }

    return maxArea;
}

int main()
{

    vector<vector<char>> matrix = {{'1'}};
    cout << maximalRectangle(matrix) << endl;

    return 0;
}