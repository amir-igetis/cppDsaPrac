#include <bits/stdc++.h>
using namespace std;

// greedy

/// Let n be the length of the string.
///
/// Time complexity: O(n).
///
/// We traverse the string once.
///
/// Space complexity: O(1).
///
/// Only a constant amount of extra space is needed.
int minInsertions(string s)
{
    int insertions = 0;
    int leftCount = 0;
    int length = s.size();
    int index = 0;
    while (index < length)
    {
        char c = s[index];
        if (c == '(')
        {
            leftCount++;
            index++;
        }
        else
        {
            if (leftCount > 0)
            {
                leftCount--;
            }
            else
            {
                insertions++;
            }
            if (index < length - 1 && s[index + 1] == ')')
            {
                index += 2;
            }
            else
            {
                insertions++;
                index++;
            }
        }
    }
    insertions += leftCount * 2;
    return insertions;
}

int main()
{
    string s = "))())(";
    cout << minInsertions(s) << endl;

    return 0;
}