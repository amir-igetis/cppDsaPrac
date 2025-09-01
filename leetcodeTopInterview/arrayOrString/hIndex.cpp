#include <bits/stdc++.h>
using namespace std;

int hIndex(vector<int> &citations)
{
    sort(citations.begin(), citations.end());
    int n = citations.size();
    for (int i = 0; i < n; i++)
    {
        if (citations[i] >= n - i)
            return n - i;
    }
    return 0;
}

int hIndexI(vector<int> &citations)
{
    int papers = citations.size();
    vector<int> citaBuckets(papers + 1);
    for (int i : citations)
    {
        citaBuckets[min(i, papers)]++;
    }

    int cumulativePapers = 0;
    for (int hIndex = papers; hIndex >= 0; hIndex--)
    {
        cumulativePapers += citaBuckets[hIndex];
        if (cumulativePapers >= hIndex)
            return hIndex;
    }
    return 0;
}

int main()
{
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << hIndexI(citations) << endl;
    return 0;
}