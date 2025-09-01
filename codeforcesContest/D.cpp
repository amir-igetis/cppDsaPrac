#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void max_beautiful_segments(int test_cases)
{
    while (test_cases--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        unordered_map<long long, int> prefix_map;
        prefix_map[0] = -1;
        long long prefix_sum = 0;
        int last_cut = -1;
        int beautiful_segments = 0;

        for (int i = 0; i < n; i++)
        {
            prefix_sum += a[i];

            if (prefix_map.find(prefix_sum) != prefix_map.end())
            {
                if (prefix_map[prefix_sum] >= last_cut)
                {
                    beautiful_segments++;
                    last_cut = i;
                }
            }
            prefix_map[prefix_sum] = i;
        }

        cout << beautiful_segments << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    max_beautiful_segments(t);
    return 0;
}
