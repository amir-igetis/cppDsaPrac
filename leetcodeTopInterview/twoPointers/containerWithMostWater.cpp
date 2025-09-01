#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{

    int start = 0, end = height.size() - 1;
    int area = 0;
    while (end > start)
    {
        int startHeight = height[start];
        int endHeight = height[end];
        int minHeight = min(startHeight, endHeight);
        int length = end - start;
        int newArea = minHeight * length;
        area = max(newArea, area);
        if (endHeight >= startHeight)
            start++;
        else
            end--;
    }
    return area;
}

int main()
{

    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    cout << maxArea(height) << endl;

    return 0;
}