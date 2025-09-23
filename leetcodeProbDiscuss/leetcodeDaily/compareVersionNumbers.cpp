#include <bits/stdc++.h>
using namespace std;

int compareVersion(string version1, string version2)
{
    int i = 0, j = 0;
    int n1 = version1.size(), n2 = version2.size();

    while (i < n1 || j < n2)
    {
        int num1 = 0, num2 = 0;
        while (i < n1 && version1[i] != '.')
        {
            num1 = num1 * 10 + (version1[i] - '0');
            i++;
        }
        while (j < n2 && version2[j] != '.')
        {
            num2 = num2 * 10 + (version2[j] - '0');
            j++;
        }

        if (num1 < num2)
            return -1;
        if (num1 > num2)
            return 1;

        i++;
        j++;
    }

    return 0;
}

int main()
{
    string version1 = "1.2", version2 = "1.10";
    cout << compareVersion(version1, version2) << endl; // should print -1

    version1 = "1.01", version2 = "1.001";
    cout << compareVersion(version1, version2) << endl; // should print 0

    version1 = "1.0.5", version2 = "1.0.3";
    cout << compareVersion(version1, version2) << endl; // should print 1

    return 0;
}
