#include <bits/stdc++.h>
using namespace std;

/*
Let n be the length of the string.

Time complexity: O(n)

Iterating through the word string to count the frequency of each letter takes O(n).

Sorting the frequency array, which has a fixed size of 26 (for each letter in the alphabet), takes O(1) because the size of the array is constant.

Iterating through the frequency array to compute the total number of presses is O(1) because the array size is constant.

Overall, the dominant term is O(n) due to the frequency counting step.

Space complexity: O(1)

Frequency array and sorting takes O(1) space, as it always requires space for 26 integers.

Overall, the space complexity is O(1) because the space used does not depend on the input size.
*/
int minimumPushes(string word)
{
    vector<int> frequency(26, 0);

    // Count frequency of each character
    for (char c : word)
    {
        frequency[c - 'a']++;
    }

    // Sort in descending order
    sort(frequency.begin(), frequency.end(), greater<int>());

    int totalPushes = 0;

    for (int i = 0; i < 26; i++)
    {
        if (frequency[i] == 0)
            break;

        totalPushes += (i / 8 + 1) * frequency[i];
    }

    return totalPushes;
}

/*
Let n be the length of the string.

Time complexity: O(n)

Iterating through the word string to count the frequency of each letter takes O(n).

Inserting each frequency into the priority queue and extracting the maximum frequency both operate with a time complexity of O(klogk), where k represents the number of distinct letters. Each of these operations—insertions, and extractions—is logarithmic due to the heap structure of the priority queue. However, since the number of distinct letters is limited to a maximum of 26 (one for each letter in the alphabet), the size of the priority queue remains constant and thus the time complexity effectively becomes O(1) in practice.

Overall, the dominant term is O(n) due to the frequency counting step.

Space complexity: O(1)

The frequency map and priority queue take O(26)=O(1) space, as it always requires a fixed space for 26 integers.

Overall, the space complexity is O(1) because the space used does not depend on the input size.
*/
int minimumPushesI(string word)
{
    unordered_map<char, int> frequencyMap;

    // Count frequency
    for (char c : word)
    {
        frequencyMap[c]++;
    }

    // Max Heap
    priority_queue<int> pq;

    for (auto &entry : frequencyMap)
    {
        pq.push(entry.second);
    }

    int totalPushes = 0;
    int index = 0;

    while (!pq.empty())
    {
        totalPushes += (index / 8 + 1) * pq.top();
        pq.pop();
        index++;
    }

    return totalPushes;
}

int main()
{
    string word = "abcde";

    cout << minimumPushes(word) << endl;
    cout << minimumPushesI(word) << endl;

    return 0;
}