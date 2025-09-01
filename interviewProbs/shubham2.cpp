#include <bits/stdc++.h>
using namespace std;

int calculateMaxDistance(const vector<pair<int, int>> &offices, int w, int h)
{
    int maxDist = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            int minDist = INT_MAX;
            for (const auto &office : offices)
            {
                int dist = abs(office.first - i) + abs(office.second - j);
                if (dist < minDist)
                {
                    minDist = dist;
                }
            }
            if (minDist > maxDist)
            {
                maxDist = minDist;
            }
        }
    }
    return maxDist;
}

void findOptimalPlacement(int w, int h, int n, vector<pair<int, int>> &current, int start, int &minMaxDist)
{
    if (current.size() == n)
    {
        int currentMaxDist = calculateMaxDistance(current, w, h);
        if (currentMaxDist < minMaxDist)
        {
            minMaxDist = currentMaxDist;
        }
        return;
    }
    for (int i = start; i < w * h; ++i)
    {
        int x = i / w;
        int y = i % w;
        current.emplace_back(x, y);
        findOptimalPlacement(w, h, n, current, i + 1, minMaxDist);
        current.pop_back();
    }
}

int findMinDistance(int w, int h, int n)
{
    vector<pair<int, int>> current;
    int minMaxDist = INT_MAX;
    findOptimalPlacement(w, h, n, current, 0, minMaxDist);
    return minMaxDist;
}

int main()
{

    vector<int> ans;

    vector<vector<int>> ansI;

    int w = 5, h = 1, n = 1;
    cout << findMinDistance(w, h, n) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int countPromotionalPeriods(vector<int> &orders)
// {
//     int n = orders.size();
//     int count = 0;
//     stack<int> s;
//     vector<int> previousGreater(n, -1);
//     vector<int> nextGreater(n, n);

//     for (int i = 0; i < n; ++i)
//     {
//         while (!s.empty() && orders[s.top()] <= orders[i])
//         {
//             s.pop();
//         }
//         if (!s.empty())
//         {
//             previousGreater[i] = s.top();
//         }
//         s.push(i);
//     }
//     while (!s.empty())
//         s.pop();

//     for (int i = n - 1; i >= 0; --i)
//     {
//         while (!s.empty() && orders[s.top()] <= orders[i])
//         {
//             s.pop();
//         }
//         if (!s.empty())
//         {
//             nextGreater[i] = s.top();
//         }
//         s.push(i);
//     }

//     for (int i = 1; i < n - 1; ++i)
//     {
//         int left = previousGreater[i];
//         int right = nextGreater[i];
//         if (left != -1 && right != n)
//         {
//             count++;
//         }
//     }

//     return count;
// }

// int main()
// {
//     // vector<int> orders = {10, 6, 8, 5, 11, 9};
//     vector<int> orders = {5, 2, 1, 3, 6};
//     cout << countPromotionalPeriods(orders) << endl;
//     return 0;
// }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int countPromotionalPeriods(vector<int> &orders)
// // {
// //     int n = orders.size();

// //     vector<int> log2(n + 1);
// //     log2[1] = 0;
// //     for (int i = 2; i <= n; ++i)
// //         log2[i] = log2[i / 2] + 1;

// //     int maxLog = log2[n] + 1;
// //     vector<vector<int>> st(n, vector<int>(maxLog));

// //     for (int i = 0; i < n; ++i)
// //         st[i][0] = orders[i];

// //     for (int j = 1; (1 << j) <= n; ++j)
// //     {
// //         for (int i = 0; i + (1 << j) <= n; ++i)
// //         {
// //             st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
// //         }
// //     }

// //     auto queryMax = [&](int L, int R)
// //     {
// //         int j = log2[R - L + 1];
// //         return max(st[L][j], st[R - (1 << j) + 1][j]);
// //     };

// //     int count = 0;
// //     for (int i = 0; i <= n - 3; ++i)
// //     {
// //         for (int j = i + 2; j < n; ++j)
// //         {
// //             int midMax = queryMax(i + 1, j - 1);
// //             if (min(orders[i], orders[j]) > midMax)
// //                 count++;
// //         }
// //     }

// //     return count;
// // }

// // int main()
// // {
// //     // vector<int> orders = {5, 2, 1, 3, 6};
// //     vector<int> orders = {10, 6, 8, 5, 11, 9};
// //     cout << countPromotionalPeriods(orders) << endl;

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// int countPromotionalPeriods(vector<int> &orders)
// {
//     int n = orders.size();
//     if (n < 3)
//         return 0;

//     int count = 0;

//     for (int i = 0; i <= n - 3; ++i)
//     {
//         int maxInBetween = 0;

//         for (int j = i + 2; j < n; ++j)
//         {
//             maxInBetween = max(maxInBetween, orders[j - 1]);

//             if (orders[i] <= maxInBetween)
//                 break;

//             if (orders[j] > maxInBetween)
//             {
//                 count++;
//             }
//         }
//     }

//     return count;
// }

// int main()
// {
//     // vector<int> orders = {10, 6, 8, 5, 11, 9};
//     vector<int> orders = {5, 2, 1, 3, 6};

//     cout << countPromotionalPeriods(orders) << endl;

//     return 0;
// }