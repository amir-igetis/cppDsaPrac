#include <bits/stdc++.h>
using namespace std;

// Binary search solution
double separateSquares(vector<vector<int>> &squares)
{
    double max_y = 0, total_area = 0;

    for (int i = 0; i < squares.size(); i++)
    {
        int y = squares[i][1];
        int l = squares[i][2];
        total_area += (double)l * l;
        max_y = max(max_y, (double)(y + l));
    }

    auto check = [&](double limit_y)
    {
        double area = 0;
        for (int i = 0; i < squares.size(); i++)
        {
            int y = squares[i][1];
            int l = squares[i][2];
            if (y < limit_y)
            {
                area += l * min(limit_y - y, (double)l);
            }
        }
        return area >= total_area / 2;
    };

    double lo = 0, hi = max_y;
    double eps = 1e-5;

    while (hi - lo > eps)
    {
        double mid = (lo + hi) / 2;
        if (check(mid))
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

// Sweep line solution
double separateSquaresI(vector<vector<int>> &squares)
{
    long long total_area = 0;
    vector<tuple<int, int, int>> events;

    for (int i = 0; i < squares.size(); i++)
    {
        int y = squares[i][1];
        int l = squares[i][2];
        total_area += (long long)l * l;
        events.push_back(make_tuple(y, l, 1));      // start
        events.push_back(make_tuple(y + l, l, -1)); // end
    }

    sort(events.begin(), events.end(),
         [](const tuple<int, int, int> &a,
            const tuple<int, int, int> &b)
         {
             return get<0>(a) < get<0>(b);
         });

    double covered_width = 0;
    double curr_area = 0;
    double prev_height = 0;

    for (int i = 0; i < events.size(); i++)
    {
        int y = get<0>(events[i]);
        int l = get<1>(events[i]);
        int delta = get<2>(events[i]);

        double diff = y - prev_height;
        double area = covered_width * diff;

        if (2.0 * (curr_area + area) >= total_area)
        {
            return prev_height +
                   (total_area - 2.0 * curr_area) /
                       (2.0 * covered_width);
        }

        covered_width += delta * l;
        curr_area += area;
        prev_height = y;
    }

    return 0.0;
}

int main()
{
    vector<vector<int>> squares = {{0, 0, 1}, {2, 2, 1}};
    cout << separateSquares(squares) << endl;
    cout << separateSquaresI(squares) << endl;
    return 0;
}
