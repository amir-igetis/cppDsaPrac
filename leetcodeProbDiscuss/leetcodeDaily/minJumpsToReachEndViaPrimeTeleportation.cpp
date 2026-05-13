#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
    if (x < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> getPrimeFactors(int x)
{
    vector<int> factors;

    for (int p = 2; p * p <= x; p++)
    {
        if (x % p == 0)
        {
            factors.push_back(p);

            while (x % p == 0)
            {
                x /= p;
            }
        }
    }

    if (x > 1)
    {
        factors.push_back(x);
    }

    return factors;
}

int minJumps(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, vector<int>> divisibleMap;

    // Store indices divisible by each prime factor
    for (int i = 0; i < n; i++)
    {
        vector<int> factors = getPrimeFactors(nums[i]);

        for (int p : factors)
        {
            divisibleMap[p].push_back(i);
        }
    }

    queue<int> q;
    vector<bool> visited(n, false);

    // Avoid using same prime teleport multiple times
    unordered_set<int> usedPrime;

    q.push(0);
    visited[0] = true;

    int jumps = 0;

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            int i = q.front();
            q.pop();

            // Reached destination
            if (i == n - 1)
            {
                return jumps;
            }

            // Left move
            if (i - 1 >= 0 && !visited[i - 1])
            {
                visited[i - 1] = true;
                q.push(i - 1);
            }

            // Right move
            if (i + 1 < n && !visited[i + 1])
            {
                visited[i + 1] = true;
                q.push(i + 1);
            }

            // Prime teleportation
            if (isPrime(nums[i]) &&
                usedPrime.find(nums[i]) == usedPrime.end())
            {
                int p = nums[i];

                usedPrime.insert(p);

                for (int idx : divisibleMap[p])
                {
                    if (!visited[idx])
                    {
                        visited[idx] = true;
                        q.push(idx);
                    }
                }
            }
        }

        jumps++;
    }

    return -1;
}

int main()
{

    vector<int> nums = {1, 2, 4, 6};

    cout << minJumps(nums) << endl;

    return 0;
}