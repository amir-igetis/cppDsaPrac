#include <bits/stdc++.h>
using namespace std;

vector<int> numsAns;

void dfs(int low, int high, int digit, int num)
{
    if (num >= low && num <= high)
        numsAns.push_back(num);

    // Stop if number exceeds high or digit becomes invalid
    if (num > high || digit > 9)
        return;

    dfs(low, high, digit + 1, num * 10 + digit);
}

// -------------------------------------------------------
// BFS Solution
// Time : O(Count of generated numbers) ≈ O(1)
// Space: O(1)
// -------------------------------------------------------
vector<int> sequentialDigits(int low, int high)
{

    queue<int> q;

    for (int i = 1; i <= 9; i++)
        q.push(i);

    vector<int> ans;

    while (!q.empty())
    {

        int curr = q.front();
        q.pop();

        if (curr >= low && curr <= high)
            ans.push_back(curr);

        if (curr > high)
            break;

        int lastDigit = curr % 10;

        if (lastDigit < 9)
            q.push(curr * 10 + (lastDigit + 1));
    }

    return ans;
}

// -------------------------------------------------------
// DFS Solution
// Time : O(Count of generated numbers) ≈ O(1)
// Space: O(Recursion depth) ≈ O(9)
// -------------------------------------------------------
vector<int> sequentialDigitsI(int low, int high)
{

    numsAns.clear();

    for (int i = 1; i <= 9; i++)
        dfs(low, high, i, 0);

    sort(numsAns.begin(), numsAns.end());

    return numsAns;
}

int main()
{

    int low = 100;
    int high = 300;

    vector<int> ans = sequentialDigits(low, high);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    ans = sequentialDigitsI(low, high);

    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}