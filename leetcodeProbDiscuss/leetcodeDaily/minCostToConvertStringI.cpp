#include <bits/stdc++.h>
using namespace std;

// Find minimum conversion costs from a starting character to all other
// characters

vector<long long> dijkstra(
    int startChar, const vector<vector<pair<int, int>>> &adjacencyList)
{
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;

    pq.push({0, startChar});

    vector<long long> minCosts(26, -1);

    while (!pq.empty())
    {
        pair<long long, int> top = pq.top();
        pq.pop();

        long long currentCost = top.first;
        int currentChar = top.second;

        if (minCosts[currentChar] != -1 &&
            minCosts[currentChar] < currentCost)
            continue;

        for (int i = 0; i < adjacencyList[currentChar].size(); i++)
        {
            int targetChar = adjacencyList[currentChar][i].first;
            int conversionCost = adjacencyList[currentChar][i].second;

            long long newTotalCost = currentCost + conversionCost;

            if (minCosts[targetChar] == -1 ||
                newTotalCost < minCosts[targetChar])
            {
                minCosts[targetChar] = newTotalCost;
                pq.push({newTotalCost, targetChar});
            }
        }
    }

    return minCosts;
}

long long minimumCost(string source, string target, vector<char> &original,
                      vector<char> &changed, vector<int> &cost)
{
    vector<vector<pair<int, int>>> adjacencyList(26);

    for (int i = 0; i < original.size(); i++)
    {
        adjacencyList[original[i] - 'a'].push_back(
            {changed[i] - 'a', cost[i]});
    }

    vector<vector<long long>> minConversionCosts(26, vector<long long>(26));
    for (int i = 0; i < 26; i++)
    {
        minConversionCosts[i] = dijkstra(i, adjacencyList);
    }

    long long totalCost = 0;

    for (int i = 0; i < source.length(); i++)
    {
        if (source[i] != target[i])
        {
            long long charConversionCost =
                minConversionCosts[source[i] - 'a'][target[i] - 'a'];

            if (charConversionCost == -1)
                return -1;

            totalCost += charConversionCost;
        }
    }

    return totalCost;
}

//    floyd warsall algo tc O(m + n) and sc O(1)

long long minimumCostI(string source, string target, vector<char> &original,
                       vector<char> &changed, vector<int> &cost)
{
    // Initialize result to store the total minimum cost
    long long totalCost = 0;

    // Initialize a 2D vector to store the minimum transformation cost
    // between any two characters
    vector<vector<long long>> minCost(26, vector<long long>(26, INT_MAX));

    // Fill the initial transformation costs from the given original,
    // changed, and cost arrays
    for (int i = 0; i < original.size(); ++i)
    {
        int startChar = original[i] - 'a';
        int endChar = changed[i] - 'a';
        minCost[startChar][endChar] =
            min(minCost[startChar][endChar], (long long)cost[i]);
    }

    // Use Floyd-Warshall algorithm to find the shortest path between any
    // two characters
    for (int k = 0; k < 26; ++k)
    {
        for (int i = 0; i < 26; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                minCost[i][j] =
                    min(minCost[i][j], minCost[i][k] + minCost[k][j]);
            }
        }
    }

    // Calculate the total minimum cost to transform the source string to
    // the target string
    for (int i = 0; i < source.size(); ++i)
    {
        if (source[i] == target[i])
        {
            continue;
        }
        int sourceChar = source[i] - 'a';
        int targetChar = target[i] - 'a';

        // If the transformation is not possible, return -1
        if (minCost[sourceChar][targetChar] >= INT_MAX)
        {
            return -1;
        }
        totalCost += minCost[sourceChar][targetChar];
    }

    return totalCost;
}

int main()
{

    string source = "abcd", target = "acbe";
    vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
    vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
    vector<int> cost = {2, 5, 5, 1, 2, 20};

    cout << minimumCostI(source, target, original, changed, cost) << endl;

    return 0;
}