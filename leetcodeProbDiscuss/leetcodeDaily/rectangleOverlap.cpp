#include <bits/stdc++.h>
using namespace std;

// check Position
bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
{
    // check if either rectangle is actually a line
    if (rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
        rec2[0] == rec2[2] || rec2[1] == rec2[3])
    {
        // the line cannot have positive overlap
        return false;
    }

    return !(rec1[2] <= rec2[0] || // left
             rec1[3] <= rec2[1] || // bottom
             rec1[0] >= rec2[2] || // right
             rec1[1] >= rec2[3]);  // top
}

// check Area
bool isRectangleOverlapI(vector<int> &rec1, vector<int> &rec2)
{
    return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && // width > 0
            min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));  // height > 0
}

int main()
{

    vector<int> rec1 = {0, 0, 2, 2}, rec2 = {1, 1, 3, 3};
    cout << (isRectangleOverlap(rec1, rec2) ? "True" : "False") << endl;
    cout << (isRectangleOverlapI(rec1, rec2) ? "True" : "False") << endl;

    return 0;
}