#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(const vector<int> &count)
{
    for (int d = 1; d <= 7; d++)
    {
        if (count[d] != 0 && count[d] != d)
            return false;
    }

    return true;
}

void generate(long num, vector<int> &count, vector<int> &list)
{
    if (num > 0 && isBeautiful(count))
        list.push_back((int)num);

    if (num > 1224444)
        return;

    for (int d = 1; d <= 7; d++)
    {
        if (count[d] < d)
        {
            count[d]++;
            generate(num * 10 + d, count, list);
            count[d]--;
        }
    }
}

int nextBeautifulNumber(int n)
{
    vector<int> list, count(10, 0);
    generate(0, count, list);
    sort(list.begin(), list.end());

    for (auto &num : list)
    {
        if (num > n)
            return num;
    }

    return -1;
}

int main()
{

    int n = 1;

    cout << nextBeautifulNumber(n) << endl;
}