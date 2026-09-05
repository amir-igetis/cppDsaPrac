#include <bits/stdc++.h>
using namespace std;

// BFS
/// Let m and n be the number of rows and columns of the matrix respectively, energy be the total energy, and k be the number of occurrences of ’L’ in the matrix.
///
/// Time complexity: O(mn⋅energy⋅2^k)
///
/// The state is determined by position and a binary mask, and the corresponding energy bestEnergy[x][y][mask] for the same position and mask may take up to energy different values.
///
/// Space complexity: O(mn⋅energy⋅2^k)
///
/// This is the space required by the queue.

static constexpr int dx[4] = {0, 1, 0, -1};
static constexpr int dy[4] = {1, 0, -1, 0};

int minMoves(vector<string> &classroom, int energy)
{
    int m = classroom.size();
    int n = classroom[0].size();
    vector<vector<int>> id(m, vector<int>(n, 0));
    int sx, sy, cnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (classroom[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            else if (classroom[i][j] == 'L')
            {
                id[i][j] = 1 << cnt++;
            }
        }
    }

    vector<vector<vector<int>>> bestEnergy(m, vector<vector<int>>(n, vector<int>(1 << cnt, -1)));
    bestEnergy[sx][sy][0] = energy;
    struct Info
    {
        int x, y, mask, e, steps;
    };
    queue<Info> q;
    q.push({sx, sy, 0, energy, 0});
    while (!q.empty())
    {
        Info t = q.front();
        q.pop();
        if (t.mask == (1 << cnt) - 1)
        {
            return t.steps;
        }
        if (t.e == 0)
        {
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = t.x + dx[i];
            int ny = t.y + dy[i];

            if (nx < 0 || nx >= m || ny < 0 || ny >= n ||
                classroom[nx][ny] == 'X')
            {
                continue;
            }

            int ne = classroom[nx][ny] == 'R' ? energy : t.e - 1;
            int nmask = t.mask | id[nx][ny];

            if (ne > bestEnergy[nx][ny][nmask])
            {
                bestEnergy[nx][ny][nmask] = ne;
                q.push({nx, ny, nmask, ne, t.steps + 1});
            }
        }
    }
    return -1;
}

int main()
{
    vector<string> classroom = {"S.", "XL"};
    int energy = 2;
    cout << minMoves(classroom, energy) << endl;

    return 0;
}