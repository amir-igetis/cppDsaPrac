#include <bits/stdc++.h>
using namespace std;

// Binary Search + Dynamic Programming tc O(nlogm+nlogn+mlogm). Space complexity: O(n+logm).

int maxWalls(vector<int> &robots, vector<int> &distance,
             vector<int> &walls)
{
    int n = robots.size();
    int pos1, pos2, pos3, leftPos, rightPos;
    vector<int> left(n, 0), right(n, 0), num(n, 0);
    unordered_map<int, int> robotsToDistance;
    for (int i = 0; i < n; i++)
    {
        robotsToDistance[robots[i]] = distance[i];
    }
    sort(robots.begin(), robots.end());
    sort(walls.begin(), walls.end());
    for (int i = 0; i < n; i++)
    {
        pos1 = upper_bound(walls.begin(), walls.end(), robots[i]) -
               walls.begin();
        if (i >= 1)
        {
            leftPos =
                lower_bound(walls.begin(), walls.end(),
                            max(robots[i] - robotsToDistance[robots[i]],
                                robots[i - 1] + 1)) -
                walls.begin();
        }
        else
        {
            leftPos = lower_bound(walls.begin(), walls.end(),
                                  robots[i] - robotsToDistance[robots[i]]) -
                      walls.begin();
        }
        left[i] = pos1 - leftPos;
        if (i < n - 1)
        {
            rightPos =
                upper_bound(walls.begin(), walls.end(),
                            min(robots[i] + robotsToDistance[robots[i]],
                                robots[i + 1] - 1)) -
                walls.begin();
        }
        else
        {
            rightPos =
                upper_bound(walls.begin(), walls.end(),
                            robots[i] + robotsToDistance[robots[i]]) -
                walls.begin();
        }
        pos2 = lower_bound(walls.begin(), walls.end(), robots[i]) -
               walls.begin();
        right[i] = rightPos - pos2;
        if (i == 0)
        {
            continue;
        }
        pos3 = lower_bound(walls.begin(), walls.end(), robots[i - 1]) -
               walls.begin();
        num[i] = pos1 - pos3;
    }
    int subLeft, subRight, currentLeft, currentRight;
    subLeft = left[0];
    subRight = right[0];
    for (int i = 1; i < n; i++)
    {
        currentLeft =
            max(subLeft + left[i], subRight - right[i - 1] +
                                       min(left[i] + right[i - 1], num[i]));
        currentRight = max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }
    return max(subLeft, subRight);
}

// Two Pointers + Dynamic Programming tc O(nlogm+mlogm). Space complexity: O(n+logm).

int maxWallsI(vector<int> &robots, vector<int> &distance,
              vector<int> &walls)
{
    int n = robots.size();
    vector<int> left(n, 0), right(n, 0), num(n, 0);
    unordered_map<int, int> robotsToDistance;

    for (int i = 0; i < n; i++)
    {
        robotsToDistance[robots[i]] = distance[i];
    }

    sort(robots.begin(), robots.end());
    sort(walls.begin(), walls.end());

    int m = walls.size();
    int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

    for (int i = 0; i < n; i++)
    {
        // rightPtr finds the position of the first element greater than
        // robots[i] (corresponding to upper_bound)
        while (rightPtr < m && walls[rightPtr] <= robots[i])
        {
            rightPtr++;
        }
        int pos1 = rightPtr;

        // curPtr finds the position of the first element >= robots[i]
        // (corresponding to lower_bound, used for calculating right[i])
        while (curPtr < m && walls[curPtr] < robots[i])
        {
            curPtr++;
        }
        int pos2 = curPtr;

        // leftPtr finds the first wall >= the left boundary
        int leftBound = (i >= 1)
                            ? max(robots[i] - robotsToDistance[robots[i]],
                                  robots[i - 1] + 1)
                            : robots[i] - robotsToDistance[robots[i]];
        while (leftPtr < m && walls[leftPtr] < leftBound)
        {
            leftPtr++;
        }
        int leftPos = leftPtr;
        left[i] = pos1 - leftPos;

        // Count the number of walls that can be reached on the right side
        // The right boundary needs to consider the overlapping area with
        // the next robot
        int rightBound = (i < n - 1)
                             ? min(robots[i] + robotsToDistance[robots[i]],
                                   robots[i + 1] - 1)
                             : robots[i] + robotsToDistance[robots[i]];
        // Find the first wall greater than the right boundary
        while (rightPtr < m && walls[rightPtr] <= rightBound)
        {
            rightPtr++;
        }
        int rightPos = rightPtr;
        right[i] = rightPos - pos2;

        if (i == 0)
        {
            continue;
        }
        // robotPtr finds the position of the previous robot
        while (robotPtr < m && walls[robotPtr] < robots[i - 1])
        {
            robotPtr++;
        }
        int pos3 = robotPtr;
        num[i] = pos1 - pos3;
    }

    int subLeft = left[0], subRight = right[0];
    for (int i = 1; i < n; i++)
    {
        int currentLeft =
            max(subLeft + left[i], subRight - right[i - 1] +
                                       min(left[i] + right[i - 1], num[i]));
        int currentRight = max(subLeft + right[i], subRight + right[i]);
        subLeft = currentLeft;
        subRight = currentRight;
    }
    return max(subLeft, subRight);
}

// Two Pointers + Dynamic Programming + Space Optimization tc O(nlogm+mlogm). Space complexity: O(n+logm).

int maxWallsII(vector<int> &robots, vector<int> &distance,
               vector<int> &walls)
{
    int n = robots.size();
    vector<pair<int, int>> robotDist;
    for (int i = 0; i < n; i++)
    {
        robotDist.push_back({robots[i], distance[i]});
    }
    sort(robotDist.begin(), robotDist.end());
    sort(walls.begin(), walls.end());

    int m = walls.size();
    int rightPtr = 0, leftPtr = 0, curPtr = 0, robotPtr = 0;

    // DP variable: saves only the previous value
    int prevLeft = 0, prevRight = 0, prevNum = 0;
    int subLeft = 0, subRight = 0;

    for (int i = 0; i < n; i++)
    {
        int robotPos = robotDist[i].first;
        int robotDistVal = robotDist[i].second;

        // rightPtr finds the first position greater than robotPos
        // (corresponding to upper_bound)
        while (rightPtr < m && walls[rightPtr] <= robotPos)
        {
            rightPtr++;
        }
        int pos1 = rightPtr;

        // curPtr finds the first position >= robotPos (corresponding to
        // lower_bound)
        while (curPtr < m && walls[curPtr] < robotPos)
        {
            curPtr++;
        }
        int pos2 = curPtr;

        // leftPtr finds the first wall >= the left boundary
        int leftBound = (i >= 1) ? max(robotPos - robotDistVal,
                                       robotDist[i - 1].first + 1)
                                 : robotPos - robotDistVal;
        while (leftPtr < m && walls[leftPtr] < leftBound)
        {
            leftPtr++;
        }
        int leftPos = leftPtr;
        int currentLeft = pos1 - leftPos;

        // Count the number of walls that can be reached on the right side
        int rightBound = (i < n - 1) ? min(robotPos + robotDistVal,
                                           robotDist[i + 1].first - 1)
                                     : robotPos + robotDistVal;
        while (rightPtr < m && walls[rightPtr] <= rightBound)
        {
            rightPtr++;
        }
        int rightPos = rightPtr;
        int currentRight = rightPos - pos2;

        // robotPtr finds the position of the previous robot
        int currentNum = 0;
        if (i > 0)
        {
            while (robotPtr < m &&
                   walls[robotPtr] < robotDist[i - 1].first)
            {
                robotPtr++;
            }
            int pos3 = robotPtr;
            currentNum = pos1 - pos3;
        }

        if (i == 0)
        {
            subLeft = currentLeft;
            subRight = currentRight;
        }
        else
        {
            int newsubLeft =
                max(subLeft + currentLeft,
                    subRight - prevRight +
                        min(currentLeft + prevRight, currentNum));
            int newsubRight =
                max(subLeft + currentRight, subRight + currentRight);
            subLeft = newsubLeft;
            subRight = newsubRight;
        }

        prevLeft = currentLeft;
        prevRight = currentRight;
        prevNum = currentNum;
    }

    return max(subLeft, subRight);
}

int main()
{

    vector<int> robots = {10, 2}, distance = {5, 1}, walls = {5, 2, 7};
    cout << maxWallsII(robots, distance, walls) << endl;

    return 0;
}