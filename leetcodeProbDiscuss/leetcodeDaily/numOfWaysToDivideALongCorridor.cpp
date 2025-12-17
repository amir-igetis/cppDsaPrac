#include <bits/stdc++.h>
using namespace std;

//    top down dynamic approach

// giving TLE

// Store 1000000007 in a variable for convenience
const int MOD = 1e9 + 7;

int count(int index, int seats, string &corridor, int cache[][3])
{
    if (index == corridor.length())
    {
        return seats == 2 ? 1 : 0;
    }
    if (cache[index][seats] != -1)
    {
        return cache[index][seats];
    }

    int result = 0;

    if (seats == 2)
    {
        if (corridor[index] == 'S')
        {
            result = count(index + 1, 1, corridor, cache);
        }
        else
        {
            result = (count(index + 1, 0, corridor, cache) + count(index + 1, 2, corridor, cache)) % MOD;
        }
    }
    else
    {
        if (corridor[index] == 'S')
        {
            result = count(index + 1, seats + 1, corridor, cache);
        }
        else
        {
            result = count(index + 1, seats, corridor, cache);
        }
    }

    cache[index][seats] = result;
    return cache[index][seats];
}

int numberOfWays(string corridor)
{
    int cache[corridor.length()][3];
    memset(cache, -1, sizeof(cache));

    return count(0, 0, corridor, cache);
}

//    bottom up dp

int numberOfWaysI(string corridor)
{
    const int MOD = 1e9 + 7;
    int count[corridor.length() + 1][3];

    // Base cases
    count[corridor.length()][0] = 0;
    count[corridor.length()][1] = 0;
    count[corridor.length()][2] = 1;

    for (int index = corridor.length() - 1; index >= 0; index--)
    {
        if (corridor[index] == 'S')
        {
            count[index][0] = count[index + 1][1];
            count[index][1] = count[index + 1][2];
            count[index][2] = count[index + 1][1];
        }
        else
        {
            count[index][0] = count[index + 1][0];
            count[index][1] = count[index + 1][1];
            count[index][2] = (count[index + 1][0] + count[index + 1][2]) % MOD;
        }
    }

    // Return the result
    return count[0][0];
}

//    space optimized bottom up dp
static int numberOfWaysII(string corridor)
{
    const int MOD = 1e9 + 7;

    int zero = 0;
    int one = 0;
    int two = 1;

    for (char thing : corridor)
    {
        if (thing == 'S')
        {
            zero = one;
            swap(one, two);
        }
        else
        {
            two = (two + zero) % MOD;
        }
    }

    return zero;
}

//    combinatorics
static int numberOfWaysIII(string corridor)
{
    const int MOD = 1e9 + 7;

    vector<int> indices;
    for (int index = 0; index < corridor.length(); index++)
    {
        if (corridor[index] == 'S')
        {
            indices.push_back(index);
        }
    }

    if (indices.size() == 0 || indices.size() % 2 == 1)
    {
        return 0;
    }

    long count = 1;

    int previousPairLast = 1;
    int currentPairFirst = 2;
    while (currentPairFirst < indices.size())
    {
        count *= (indices[currentPairFirst] - indices[previousPairLast]);
        count %= MOD;
        previousPairLast += 2;
        currentPairFirst += 2;
    }

    return (int)count;
}

//    combinatorics, space Optimized

static int numberOfWaysV(string corridor)
{
    const int MOD = 1e9 + 7;

    long count = 1;

    int seats = 0;
    int previousPairLast = -1;

    for (int index = 0; index < corridor.length(); index++)
    {
        if (corridor[index] == 'S')
        {
            seats += 1;

            if (seats == 2)
            {
                previousPairLast = index;
                seats = 0;
            }
            else if (seats == 1 && previousPairLast != -1)
            {
                count *= (index - previousPairLast);
                count %= MOD;
            }
        }
    }

    if (seats == 1 || previousPairLast == -1)
    {
        return 0;
    }

    return (int)count;
}

int main()
{
    string corridor = "SSPPSPS";
    cout << numberOfWays(corridor) << endl;

    return 0;
}