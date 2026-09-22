#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve()
{
    long long a, b, c;
    cin >> a >> b >> c;

    // Alice takes all c stones immediately
    long long option1 = llabs((a + c) - b);

    // Alice takes 0 stones, game ends if b >= a
    long long option2 = (b > a) ? (b - a) : 0;

    long long ans = max(option1, option2);
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}