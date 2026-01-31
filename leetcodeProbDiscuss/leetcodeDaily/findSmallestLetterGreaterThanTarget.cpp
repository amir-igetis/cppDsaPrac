#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int start = 0;
    int end = letters.size() - 1;
    int ans = letters[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (letters[mid] > target)
        {
            ans = letters[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    vector<char> let = {'x', 'x', 'y', 'y'};
    char ans = 'z';
    char target = 'c';

    cout << nextGreatestLetter(letters, target) << endl;
    cout << nextGreatestLetter(let, ans) << endl;

    return 0;
}