#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    int count = 0;
    float avg = 0.0;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] % 2 != 0)
        {
            sum += arr[i];
            count++;
        }
    }
    avg = (float)sum / count;

    cout << sum << " " << count << " " << fixed << setprecision(2) << avg << endl;

    return 0;
}