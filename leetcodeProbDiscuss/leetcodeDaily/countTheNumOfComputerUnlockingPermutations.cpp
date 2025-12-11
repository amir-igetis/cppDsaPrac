#include <bits/stdc++.h>
using namespace std;

/*
check the diffference between the codes
*/
int countPermutations(vector<int> &complexity)
{
    const int MOD = 1e9 + 7;
    int n = complexity.size();
    for (int i = 1; i < n; i++)
        if (complexity[i] <= complexity[0])
            return 0;

    int fact = 1;
    for (int i = 2; i < n; i++)
        fact = (fact * i) % MOD;

    return fact;
}

// brain-teaser
int countPermutationsI(vector<int> &complexity)
{
    const int MOD = 1e9 + 7;
    int n = complexity.size();
    if (*min_element(complexity.begin() + 1, complexity.end()) <=
        complexity[0])
    {
        return 0;
    }
    int ans = 1;
    for (int i = 2; i < n; i++)
    {
        ans = static_cast<long long>(ans) * i % MOD;
    }

    return ans;
}

int main()
{

    vector<int> complexity = {1, 2, 3};
    cout << countPermutationsI(complexity) << endl;
    return 0;
}