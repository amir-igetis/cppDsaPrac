#include <bits/stdc++.h>
using namespace std;

//    three pass count method tc & sc O(n)
int minimumDeletions(string s)
{
    int n = s.length();
    vector<int> countA(n);
    vector<int> countB(n);
    int bCount = 0;
    for (int i = 0; i < n; i++)
    {
        countB[i] = bCount;
        if (s[i] == 'b')
            bCount++;
    }
    int aCount = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        countA[i] = aCount;
        if (s[i] == 'a')
            aCount++;
    }
    int minDel = n;
    for (int i = 0; i < n; i++)
    {
        minDel = min(minDel, countA[i] + countB[i]);
    }
    return minDel;
}

//    combined pass method tc & sc O(n)
static int minimumDeletionsI(string s)
{
    int n = s.length();
    vector<int> countA(n);
    int aCount = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        countA[i] = aCount;
        if (s[i] == 'a')
            aCount++;
    }
    int minDels = n;
    int bCount = 0;
    for (int i = 0; i < n; i++)
    {
        minDels = min(countA[i] + bCount, minDels);
        if (s[i] == 'b')
            bCount++;
    }
    return minDels;
}

//    two variable method tc O(n) & sc O(1)
static int minimumDeletionsII(string s)
{
    int n = s.length();
    int aCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            aCount++;
    }
    int bCount = 0;
    int minDels = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            aCount--;
        minDels = min(minDels, aCount + bCount);
        if (s[i] == 'b')
            bCount++;
    }
    return minDels;
}

//    one pass stack method tc O(n) & sc O(n)
static int minimumDeletionsIII(string s)
{
    int n = s.length();
    stack<char> st;
    int delCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (!st.empty() && st.top() == 'b' && s[i] == 'a')
        {
            st.pop();
            delCount++;
        }
        else
        {
            st.push(s[i]);
        }
    }
    return delCount;
}

int main()
{
    string s = "aababbab";
    cout << minimumDeletionsI(s) << endl;

    return 0;
}