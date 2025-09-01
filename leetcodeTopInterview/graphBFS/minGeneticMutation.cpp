#include <bits/stdc++.h>
using namespace std;

int minMutation(string startGene, string endGene, vector<string> &bank)
{
    unordered_set<string> validGenes(bank.begin(), bank.end());

    if (validGenes.find(endGene) == validGenes.end())
        return -1;

    vector<char> genes = {'A', 'C', 'G', 'T'};
    queue<string> q;
    unordered_set<string> visited;
    q.push(startGene);
    visited.insert(startGene);
    int mutations = 0;

    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            string curr = q.front();
            q.pop();

            if (curr == endGene)
                return mutations;

            string chars = curr;
            for (int j = 0; j < chars.size(); j++)
            {
                char original = chars[j];
                for (char gene : genes)
                {
                    if (gene == original)
                        continue;
                    chars[j] = gene;
                    string mutated = chars;
                    if (validGenes.count(mutated) && !visited.count(mutated))
                    {
                        q.push(mutated);
                        visited.insert(mutated);
                    }
                }
                chars[j] = original;
            }
        }
        mutations++;
    }
    return -1;
}

// Bidirectional BFS
int minMutationI(string startGene, string endGene, vector<string> &bank)
{
    unordered_set<string> validGenes(bank.begin(), bank.end());

    // If endGene is not in the bank, impossible
    if (!validGenes.count(endGene))
        return -1;

    vector<char> genes = {'A', 'C', 'G', 'T'};
    unordered_set<string> beginSet, endSet, visited;

    beginSet.insert(startGene);
    endSet.insert(endGene);

    int mutations = 0;

    while (!beginSet.empty() && !endSet.empty())
    {
        // Always expand the smaller set for efficiency
        if (beginSet.size() > endSet.size())
            swap(beginSet, endSet);

        unordered_set<string> nextLevel;

        for (auto curr : beginSet)
        {
            string chars = curr;

            for (int j = 0; j < chars.size(); j++)
            {
                char original = chars[j];
                for (char g : genes)
                {
                    if (g == original)
                        continue;

                    chars[j] = g;
                    if (endSet.count(chars))
                        return mutations + 1; // found path

                    if (validGenes.count(chars) && !visited.count(chars))
                    {
                        visited.insert(chars);
                        nextLevel.insert(chars);
                    }
                }
                chars[j] = original; // restore
            }
        }

        beginSet = nextLevel;
        mutations++;
    }
    return -1;
}

int main()
{
    string startGene = "AACCGGTT", endGene = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    cout << minMutation(startGene, endGene, bank) << endl;
    return 0;
}
