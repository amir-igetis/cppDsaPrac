#include<bits/stdc++.h>
using namespace std;


int main()
{

    vector<int> ans;

    vector<vector<int>> ansI; 
    return 0;
}





// #include <bits/stdc++.h>
// using namespace std;

// vector<vector<char>> soln(vector<vector<char>> matrix)
// {
//     int rows = matrix.size();
//     int cols = matrix[0].size();
//     vector<vector<bool>> visited(rows, vector<bool>(cols, false));
//     vector<pair<int, int>> figure;

//     vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

//     bool found = false;
//     for (int r = 0; r < rows && !found; ++r)
//     {
//         for (int c = 0; c < cols && !found; ++c)
//         {
//             if (matrix[r][c] == 'F' && !visited[r][c])
//             {
//                 queue<pair<int, int>> q;
//                 q.push(make_pair(r, c));
//                 visited[r][c] = true;

//                 while (!q.empty())
//                 {
//                     pair<int, int> cell = q.front();
//                     q.pop();
//                     int x = cell.first;
//                     int y = cell.second;
//                     figure.push_back(cell);

//                     for (int i = 0; i < 4; ++i)
//                     {
//                         int nx = x + dirs[i].first;
//                         int ny = y + dirs[i].second;
//                         if (nx >= 0 && nx < rows && ny >= 0 && ny < cols &&
//                             matrix[nx][ny] == 'F' && !visited[nx][ny])
//                         {
//                             q.push(make_pair(nx, ny));
//                             visited[nx][ny] = true;
//                         }
//                     }
//                 }

//                 found = true;
//             }
//         }
//     }

//     int fall_distance = rows;
//     for (int i = 0; i < figure.size(); ++i)
//     {
//         int r = figure[i].first;
//         int c = figure[i].second;

//         int d = 0;
//         int nr = r + 1;
//         while (nr < rows &&
//                (matrix[nr][c] == '-' || visited[nr][c]))
//         {
//             ++d;
//             ++nr;
//         }
//         fall_distance = min(fall_distance, d);
//     }

//     for (int i = 0; i < figure.size(); ++i)
//     {
//         int r = figure[i].first;
//         int c = figure[i].second;
//         matrix[r][c] = '-';
//     }

//     for (int i = 0; i < figure.size(); ++i)
//     {
//         int r = figure[i].first + fall_distance;
//         int c = figure[i].second;
//         matrix[r][c] = 'F';
//     }

//     return matrix;
// }

// int main()
// {

//     vector<vector<char>> matrix = {
//         {'F', 'F', 'F'},
//         {'-', 'F', '-'},
//         {'-', 'F', 'F'},
//         {'#', 'F', '-'},
//         {'F', 'F', '-'},
//         {'-', '-', '-'},
//         {'-', '-', '#'},
//         {'-', '-', '-'}};

//     vector<vector<char>> res = soln(matrix);
//     for (const auto &row : res)
//     {
//         for (char ch : row)
//         {
//             cout << ch << ' ';
//         }
//         cout << endl;
//     }
//     return 0;
// }