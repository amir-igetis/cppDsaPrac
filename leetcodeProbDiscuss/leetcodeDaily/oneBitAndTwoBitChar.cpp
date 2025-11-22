#include <bits/stdc++.h>
using namespace std;

bool isOneBitCharacter(vector<int> &bits)
{
    int i = 0;
    int n = bits.size();
    while (i < n - 1)
    {
        if (bits[i] == 1)
            i += 2;
        else
            i += 1;
    }

    return i == n - 1;
}

int main()
{

    vector<int> bits = {1, 0, 0};
    cout << (isOneBitCharacter(bits) ? "True" : "False") << endl;

    return 0;
}