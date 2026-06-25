#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    static constexpr long long MOD = 1000000007LL;
    using Mat = vector<vector<long long>>;

    Mat mul(const Mat &a, const Mat &b)
    {
        int n = a.size();
        int m = b[0].size();
        int p = b.size();

        Mat res(n, vector<long long>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < p; k++)
            {
                long long r = a[i][k];
                if (r == 0)
                    continue;

                for (int j = 0; j < m; j++)
                {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }

        return res;
    }

    Mat powMul(Mat base, long long exp, Mat res)
    {
        while (exp > 0)
        {
            if (exp & 1)
            {
                res = mul(res, base);
            }

            base = mul(base, base);
            exp >>= 1;
        }

        return res;
    }
};

int zigZagArrays(int n, int l, int r)
{
    int m = r - l + 1;

    if (n == 1)
        return m;

    int size = 2 * m;

    Matrix::Mat u(size, vector<long long>(size, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < i; j++)
        {
            u[i][j + m] = 1;
        }

        for (int j = i + 1; j < m; j++)
        {
            u[i + m][j] = 1;
        }
    }

    Matrix::Mat dp(1, vector<long long>(size, 1));

    Matrix mat;
    dp = mat.powMul(u, n - 1, dp);

    long long ans = 0;

    for (int i = 0; i < size; i++)
    {
        ans = (ans + dp[0][i]) % Matrix::MOD;
    }

    return (int)ans;
}

int main()
{
    int n = 3, l = 4, r = 5;

    cout << zigZagArrays(n, l, r) << '\n';

    return 0;
}