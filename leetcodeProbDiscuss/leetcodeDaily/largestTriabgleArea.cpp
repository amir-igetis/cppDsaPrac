#include <bits/stdc++.h>
using namespace std;

double triangleArea(const vector<int> &p1, const vector<int> &p2, const vector<int> &p3)
{
    return fabs(
               p1[0] * (p2[1] - p3[1]) +
               p2[0] * (p3[1] - p1[1]) +
               p3[0] * (p1[1] - p2[1])) /
           2.0;
}

double largestTriangleArea(vector<vector<int>> &points)
{
    int n = points.size();
    double maxArea = 0.0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                double area = triangleArea(points[i], points[j], points[k]);
                maxArea = max(maxArea, area);
            }
        }
    }
    return maxArea;
}

int main()
{

    vector<vector<int>> points = {
        {0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
    cout << largestTriangleArea(points) << endl;

    return 0;
}