#include <bits/stdc++.h>
using namespace std;

// Bracket matching using a stack

/// Let n be the n of the string.
///
/// Time complexity: O(n).
///
/// We only need to traverse the input string once.
///
/// Space complexity: O(1).
///
/// Apart from the answer array, we only need a constant number of variables.
vector<int> maxDepthAfterSplit(string seq)
{
    int d = 0;
    int n = seq.length();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        if (seq[i] == '(')
        {
            ++d;
            ans[i] = d % 2;
        }
        else
        {
            ans[i] = d % 2;
            --d;
        }
    }
    return ans;
}

int main()
{
    string seq = "(()())";
    vector<int> res = maxDepthAfterSplit(seq);
    for (auto &i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}