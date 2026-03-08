#include <bits/stdc++.h>
using namespace std;

// Brute Force O(2^n) Time & Space

char findKthBitI(int n, int k)
{
    string seq = "0";

    for (int i = 1; i < n && k > seq.length(); i++)
    {
        seq += '1';

        int size = seq.length();
        for (int j = size - 2; j >= 0; j--)
        {
            char inverted = (seq[j] == '1') ? '0' : '1';
            seq += inverted;
        }
    }

    return seq[k - 1];
}

// recursion O(N) time and space
char findKthBitII(int n, int k)
{
    if (n == 1)
        return '0';

    int len = (1 << n) - 1;
    int mid = len / 2 + 1;

    if (k == mid)
        return '1';
    if (k < mid)
        return findKthBitII(n - 1, k);

    char bit = findKthBitII(n - 1, len - k + 1);
    return (bit == '0') ? '1' : '0';
}

// Iterative Divide & Conquer – O(N) Time, O(1) Space
char findKthBitIII(int n, int k)
{
    int invertCount = 0;
    int len = (1 << n) - 1;

    while (k > 1)
    {
        int mid = len / 2 + 1;

        if (k == mid)
            return (invertCount % 2 == 0) ? '1' : '0';

        if (k > mid)
        {
            k = len - k + 1;
            invertCount++;
        }

        len /= 2;
    }

    return (invertCount % 2 == 0) ? '0' : '1';
}

// Bit Manipulation O(1)
char findKthBitIV(int n, int k)
{
    int positionInSection = k & -k;

    bool isInInvertedPart = (((k / positionInSection) >> 1) & 1) == 1;
    bool originalBitIsOne = (k & 1) == 0;

    if (isInInvertedPart)
        return originalBitIsOne ? '0' : '1';
    else
        return originalBitIsOne ? '1' : '0';
}

// tc ans sc O(N)
char findKthBit(int n, int k)
{
    if (n == 1)
        return '0';

    int len = (1 << n) - 1;
    int mid = len / 2 + 1;

    if (k == mid)
        return '1';
    if (k < mid)
        return findKthBit(n - 1, k);

    return (findKthBit(n - 1, len - k + 1) == '0') ? '1' : '0';
}

int main()
{
    int n = 4;
    int k = 11;
    cout << findKthBit(n, k) << endl;

    return 0;
}