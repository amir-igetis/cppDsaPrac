#include <bits/stdc++.h>
using namespace std;

int closestTarget(vector<string> &words, string target, int startIndex)
{
    int ans = words.size();
    int n = words.size();

    for (int i = 0; i < n; ++i)
    {
        if (words[i] == target)
        {
            int dist = abs(i - startIndex);
            ans = min(ans, min(dist, n - dist));
        }
    }

    return ans < n ? ans : -1;
}

int main()
{
    vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
    string target = "hello";
    int startIndex = 1;
    cout << closestTarget(words, target, startIndex) << endl;

    return 0;
}