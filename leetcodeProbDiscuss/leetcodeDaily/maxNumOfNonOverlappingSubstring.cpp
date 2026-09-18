#include <bits/stdc++.h>
using namespace std;

struct Seg
{
    int left, right;
    bool operator<(const Seg &rhs) const
    {
        if (right == rhs.right)
        {
            return left > rhs.left;
        }
        return right < rhs.right;
    }
};

// greedy

/// Let n be the length of the string, and let Σ be the size of its character set.
///
/// Time complexity: O(nΣ+ΣlogΣ).
///
/// Preprocessing the left and right endpoints of every interval takes O(nΣ) time. Greedy selection takes O(ΣlogΣ+Σ) time. Therefore, the total time complexity is O(nΣ+ΣlogΣ).
///
/// Space complexity: O(Σ).
///
/// We need O(Σ) space to record the left and right endpoints of the interval containing each character.

vector<string> maxNumOfSubstrings(string s)
{
    vector<Seg> seg(26, (Seg){-1, -1});
    // Preprocess the left and right endpoints.
    for (int i = 0; i < s.length(); ++i)
    {
        int charIdx = s[i] - 'a';
        if (seg[charIdx].left == -1)
        {
            seg[charIdx].left = seg[charIdx].right = i;
        }
        else
        {
            seg[charIdx].right = i;
        }
    }
    for (int i = 0; i < 26; ++i)
    {
        if (seg[i].left != -1)
        {
            for (int j = seg[i].left; j <= seg[i].right; ++j)
            {
                int charIdx = s[j] - 'a';
                if (seg[i].left <= seg[charIdx].left &&
                    seg[charIdx].right <= seg[i].right)
                {
                    continue;
                }
                seg[i].left = min(seg[i].left, seg[charIdx].left);
                seg[i].right = max(seg[i].right, seg[charIdx].right);
                j = seg[i].left;
            }
        }
    }
    // Greedily select intervals.
    sort(seg.begin(), seg.end());
    vector<string> ans;
    int end = -1;
    for (auto &segment : seg)
    {
        int left = segment.left, right = segment.right;
        if (left == -1)
        {
            continue;
        }
        if (end == -1 || left > end)
        {
            end = right;
            ans.emplace_back(s.substr(left, right - left + 1));
        }
    }
    return ans;
}

// greedy ChatGPT
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> maxNumOfSubstringsI(const std::string &s)
{
    int n = s.length();

    // first[c] = first occurrence of character c
    // last[c] = last occurrence of character c
    vector<int> first(26, n);
    vector<int> last(26, -1);

    // Find first and last occurrence
    for (int i = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        first[c] = min(first[c], i);
        last[c] = i;
    }

    vector<pair<int, int>> intervals;

    // Try creating a valid interval starting
    // at the first occurrence of every character.
    for (int c = 0; c < 26; c++)
    {
        if (last[c] == -1)
            continue;

        int left = first[c];
        int right = last[c];
        bool valid = true;

        for (int i = left; i <= right; i++)
        {
            int curr = s[i] - 'a';

            // This character appeared before left.
            if (first[curr] < left)
            {
                valid = false;
                break;
            }

            // This character appears after current right.
            if (last[curr] > right)
            {
                right = last[curr];
            }
        }

        if (valid)
        {
            intervals.push_back({left, right});
        }
    }

    // Sort by ending position.
    sort(intervals.begin(), intervals.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    vector<string> result;
    int prevEnd = -1;

    for (const auto &interval : intervals)
    {
        int left = interval.first;
        int right = interval.second;

        // Non-overlapping
        if (left > prevEnd)
        {
            result.push_back(s.substr(left, right - left + 1));
            prevEnd = right;
        }
    }

    return result;
}

int main()
{
    string s = "adefaddaccc";
    vector<string> result = maxNumOfSubstrings(s);
    cout << "Original solution: ";
    for (const string &str : result)
    {
        cout << str << " ";
    }
    cout << endl;
    vector<string> res = maxNumOfSubstrings(s);
    cout << "ChatGPT solution: ";
    for (const string &str : res)
    {
        cout << str << " ";
    }
    cout << endl;

    return 0;
}