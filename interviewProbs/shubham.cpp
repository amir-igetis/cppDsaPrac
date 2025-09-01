#include <bits/stdc++.h>
using namespace std;

long bioHazard(int n, vector<int> allergic, vector<int> poisonous)
{
    unordered_map<int, vector<int>> poisonousTo;
    unordered_map<int, vector<int>> allergicTo;

    for (int i = 0; i < allergic.size(); ++i)
    {
        int u = poisonous[i];
        int v = allergic[i];
        poisonousTo[u].push_back(v);
        allergicTo[v].push_back(u);
    }

    long result = 0;
    int left = 0;
    unordered_map<int, int> lastPos;

    for (int right = 0; right < n; ++right)
    {
        int bact = right + 1;
        int newLeft = left;
        if (poisonousTo.find(bact) != poisonousTo.end())
        {
            for (int victim : poisonousTo[bact])
            {
                if (lastPos.find(victim) != lastPos.end())
                {
                    newLeft = max(newLeft, lastPos[victim] + 1);
                }
            }
        }
        if (allergicTo.find(bact) != allergicTo.end())
        {
            for (int attacker : allergicTo[bact])
            {
                if (lastPos.find(attacker) != lastPos.end())
                {
                    newLeft = max(newLeft, lastPos[attacker] + 1);
                }
            }
        }
        while (left < newLeft)
        {
            lastPos.erase(left + 1);
            left++;
        }
        lastPos[bact] = right;
        result += right - left + 1;
    }
    return result;
}

int main()
{

    vector<int> ans;

    vector<vector<int>> ansI;

    int n = 5;
    vector<int> allergic = {1, 2};
    vector<int> poison = {3, 5};

    cout << bioHazard(n, allergic, poison) << endl;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// string findLongestRegex(string x, string y, string z)
// {
//     int n = x.length();

//     for (int exclude_pos = 0; exclude_pos < n; exclude_pos++)
//     {
//         if (z[exclude_pos] != x[exclude_pos] && z[exclude_pos] != y[exclude_pos])
//         {
//             string regex = "";

//             for (int i = 0; i < n; i++)
//             {
//                 regex += "[";

//                 if (i == exclude_pos)
//                 {
//                     for (char c = 'A'; c <= 'Z'; c++)
//                     {
//                         if (c != z[i])
//                         {
//                             regex += c;
//                         }
//                     }
//                 }
//                 else
//                 {
//                     for (char c = 'A'; c <= 'Z'; c++)
//                     {
//                         regex += c;
//                     }
//                 }

//                 regex += "]";
//             }

//             return regex;
//         }
//     }

//     return "-1";
// }

// bool testRegex(const string &regex, const string &test_string)
// {
//     vector<set<char>> char_sets;

//     int i = 0;
//     while (i < regex.length())
//     {
//         if (regex[i] == '[')
//         {
//             set<char> char_set;
//             i++;
//             while (i < regex.length() && regex[i] != ']')
//             {
//                 char_set.insert(regex[i]);
//                 i++;
//             }
//             char_sets.push_back(char_set);
//             i++;
//         }
//     }

//     if (char_sets.size() != test_string.length())
//     {
//         return false;
//     }

//     for (int i = 0; i < test_string.length(); i++)
//     {
//         if (char_sets[i].find(test_string[i]) == char_sets[i].end())
//         {
//             return false;
//         }
//     }

//     return true;
// }

// int main()
// {
//     // string x = "AB";
//     // string y = "BD";
//     // string z = "CD";

//     // cout << findLongestRegex(x, y, z) << endl;

//     string x = "AERB";
//     string y = "ATRC";
//     string z = "AGCB";

//     cout << findLongestRegex(x, y, z) << endl;
// }

// int main() {
//     // Test case 1
//     cout << "Test Case 1:" << endl;
//     string x1 = "AERB", y1 = "ATRC", z1 = "AGCB";
//     string result1 = findLongestRegex(x1, y1, z1);
//     cout << "Input: x='" << x1 << "', y='" << y1 << "', z='" << z1 << "'" << endl;
//     cout << "Output: " << result1 << endl;

//     // Verify the result
//     if (result1 != "-1") {
//         cout << "Verification:" << endl;
//         cout << "Matches x (" << x1 << "): " << (testRegex(result1, x1) ? "Yes" : "No") << endl;
//         cout << "Matches y (" << y1 << "): " << (testRegex(result1, y1) ? "Yes" : "No") << endl;
//         cout << "Matches z (" << z1 << "): " << (testRegex(result1, z1) ? "Yes" : "No") << endl;
//     }

//     cout << endl;

//     // Test case 2
//     cout << "Test Case 2:" << endl;
//     string x2 = "AB", y2 = "BD", z2 = "CD";
//     string result2 = findLongestRegex(x2, y2, z2);
//     cout << "Input: x='" << x2 << "', y='" << y2 << "', z='" << z2 << "'" << endl;
//     cout << "Output: " << result2 << endl;

//     // Verify the result
//     if (result2 != "-1") {
//         cout << "Verification:" << endl;
//         cout << "Matches x (" << x2 << "): " << (testRegex(result2, x2) ? "Yes" : "No") << endl;
//         cout << "Matches y (" << y2 << "): " << (testRegex(result2, y2) ? "Yes" : "No") << endl;
//         cout << "Matches z (" << z2 << "): " << (testRegex(result2, z2) ? "Yes" : "No") << endl;
//     }

//     cout << endl;

//     // Test case 3 - Edge case where no solution exists
//     cout << "Test Case 3 (No solution):" << endl;
//     string x3 = "ABC", y3 = "ABC", z3 = "ABC";
//     string result3 = findLongestRegex(x3, y3, z3);
//     cout << "Input: x='" << x3 << "', y='" << y3 << "', z='" << z3 << "'" << endl;
//     cout << "Output: " << result3 << endl;

//     return 0;
// }

// // Alternative implementation with more optimized string building
// string findLongestRegexOptimized(string x, string y, string z) {
//     int n = x.length();

//     // Find the first position where we can exclude z while including x and y
//     for (int exclude_pos = 0; exclude_pos < n; exclude_pos++) {
//         // Check if z[exclude_pos] is different from both x[exclude_pos] and y[exclude_pos]
//         if (z[exclude_pos] != x[exclude_pos] && z[exclude_pos] != y[exclude_pos]) {
//             // We can exclude z at this position
//             string regex;
//             regex.reserve(n * 28); // Pre-allocate memory for efficiency

//             for (int i = 0; i < n; i++) {
//                 regex += "[";

//                 if (i == exclude_pos) {
//                     // Exclude z[i] from this position
//                     for (char c = 'A'; c <= 'Z'; c++) {
//                         if (c != z[i]) {
//                             regex += c;
//                         }
//                     }
//                 } else {
//                     // Include all characters at other positions
//                     regex += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//                 }

//                 regex += "]";
//             }

//             return regex;
//         }
//     }

//     // If no position found where z differs from both x and y, return -1
//     return "-1";
// }

// // Function to handle input/output for competitive programming
// void solve() {
//     string x, y, z;
//     cin >> x >> y >> z;
//     cout << findLongestRegex(x, y, z) << endl;
// }

// more optimized

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // Optimization 1: Pre-computed alphabet strings
// const string FULL_ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// const int ALPHABET_SIZE = 26;

// // Optimization 2: Pre-compute all possible character sets (26 variants)
// vector<string> precomputedSets;

// void initializePrecomputedSets() {
//     precomputedSets.resize(ALPHABET_SIZE);
//     for (int exclude = 0; exclude < ALPHABET_SIZE; exclude++) {
//         string set = "";
//         for (char c = 'A'; c <= 'Z'; c++) {
//             if (c != ('A' + exclude)) {
//                 set += c;
//             }
//         }
//         precomputedSets[exclude] = set;
//     }
// }

// // Optimization 3: Most optimized version
// string findLongestRegexOptimized(const string& x, const string& y, const string& z) {
//     int n = x.length();

//     // Optimization 4: Early termination check
//     // Quick scan to see if any position allows exclusion
//     int exclude_pos = -1;
//     for (int i = 0; i < n; i++) {
//         if (z[i] != x[i] && z[i] != y[i]) {
//             exclude_pos = i;
//             break;
//         }
//     }

//     if (exclude_pos == -1) {
//         return "-1";
//     }

//     // Optimization 5: Calculate exact size needed and reserve memory
//     int total_size = n * 28; // Approximate size: n * (26 chars + 2 brackets)
//     string regex;
//     regex.reserve(total_size);

//     // Optimization 6: Build regex with minimal operations
//     char exclude_char = z[exclude_pos];
//     int exclude_index = exclude_char - 'A';

//     for (int i = 0; i < n; i++) {
//         regex += '[';

//         if (i == exclude_pos) {
//             // Use precomputed set
//             regex += precomputedSets[exclude_index];
//         } else {
//             // Use full alphabet
//             regex += FULL_ALPHABET;
//         }

//         regex += ']';
//     }

//     return regex;
// }

// // Optimization 7: Ultra-optimized version using character arrays
// string findLongestRegexUltraOptimized(const string& x, const string& y, const string& z) {
//     int n = x.length();

//     // Find exclusion position
//     int exclude_pos = -1;
//     for (int i = 0; i < n; i++) {
//         if (z[i] != x[i] && z[i] != y[i]) {
//             exclude_pos = i;
//             break;
//         }
//     }

//     if (exclude_pos == -1) {
//         return "-1";
//     }

//     // Pre-calculate exact size
//     int exact_size = n * 2 + (n - 1) * ALPHABET_SIZE + (ALPHABET_SIZE - 1);
//     string regex;
//     regex.reserve(exact_size);

//     char exclude_char = z[exclude_pos];

//     // Build regex with minimal string operations
//     for (int i = 0; i < n; i++) {
//         regex += '[';

//         if (i == exclude_pos) {
//             // Inline character generation without the excluded character
//             for (char c = 'A'; c <= 'Z'; c++) {
//                 if (c != exclude_char) {
//                     regex += c;
//                 }
//             }
//         } else {
//             regex += FULL_ALPHABET;
//         }

//         regex += ']';
//     }

//     return regex;
// }

// // Optimization 8: Memory-efficient version for very large n
// string findLongestRegexMemoryOptimized(const string& x, const string& y, const string& z) {
//     int n = x.length();

//     // Find exclusion position
//     int exclude_pos = -1;
//     for (int i = 0; i < n; i++) {
//         if (z[i] != x[i] && z[i] != y[i]) {
//             exclude_pos = i;
//             break;
//         }
//     }

//     if (exclude_pos == -1) {
//         return "-1";
//     }

//     // For very large n, build string more efficiently
//     string regex;
//     char exclude_char = z[exclude_pos];

//     // Pre-build the two types of character sets
//     string full_set = "[" + FULL_ALPHABET + "]";
//     string reduced_set = "[";
//     for (char c = 'A'; c <= 'Z'; c++) {
//         if (c != exclude_char) {
//             reduced_set += c;
//         }
//     }
//     reduced_set += "]";

//     // Build final regex
//     for (int i = 0; i < n; i++) {
//         if (i == exclude_pos) {
//             regex += reduced_set;
//         } else {
//             regex += full_set;
//         }
//     }

//     return regex;
// }

// // Optimization 9: Compile-time optimization using templates
// template<bool USE_PRECOMPUTED = true>
// string findLongestRegexTemplate(const string& x, const string& y, const string& z) {
//     int n = x.length();

//     int exclude_pos = -1;
//     for (int i = 0; i < n; i++) {
//         if (z[i] != x[i] && z[i] != y[i]) {
//             exclude_pos = i;
//             break;
//         }
//     }

//     if (exclude_pos == -1) {
//         return "-1";
//     }

//     string regex;
//     regex.reserve(n * 28);

//     if constexpr (USE_PRECOMPUTED) {
//         // Use precomputed sets
//         char exclude_char = z[exclude_pos];
//         int exclude_index = exclude_char - 'A';

//         for (int i = 0; i < n; i++) {
//             regex += '[';
//             if (i == exclude_pos) {
//                 regex += precomputedSets[exclude_index];
//             } else {
//                 regex += FULL_ALPHABET;
//             }
//             regex += ']';
//         }
//     } else {
//         // Compute on-the-fly
//         char exclude_char = z[exclude_pos];

//         for (int i = 0; i < n; i++) {
//             regex += '[';
//             if (i == exclude_pos) {
//                 for (char c = 'A'; c <= 'Z'; c++) {
//                     if (c != exclude_char) {
//                         regex += c;
//                     }
//                 }
//             } else {
//                 regex += FULL_ALPHABET;
//             }
//             regex += ']';
//         }
//     }

//     return regex;
// }

// // Benchmark function
// void benchmark() {
//     // Initialize precomputed sets
//     initializePrecomputedSets();

//     // Test strings
//     string x = "AERB";
//     string y = "ATRC";
//     string z = "AGCB";

//     cout << "Testing different optimizations:" << endl;

//     // Test all versions
//     cout << "Standard: " << findLongestRegexOptimized(x, y, z) << endl;
//     cout << "Ultra-optimized: " << findLongestRegexUltraOptimized(x, y, z) << endl;
//     cout << "Memory-optimized: " << findLongestRegexMemoryOptimized(x, y, z) << endl;
//     cout << "Template (precomputed): " << findLongestRegexTemplate<true>(x, y, z) << endl;
//     cout << "Template (on-the-fly): " << findLongestRegexTemplate<false>(x, y, z) << endl;
// }

// int main() {
//     benchmark();
//     return 0;
// }

// // Final optimized solution for competitive programming
// string solve(const string& x, const string& y, const string& z) {
//     int n = x.length();

//     // Find first position where z differs from both x and y
//     for (int i = 0; i < n; i++) {
//         if (z[i] != x[i] && z[i] != y[i]) {
//             // Build regex with exclusion at position i
//             string regex;
//             regex.reserve(n * 28);

//             char exclude_char = z[i];

//             for (int j = 0; j < n; j++) {
//                 regex += '[';
//                 if (j == i) {
//                     // Exclude z[i]
//                     for (char c = 'A'; c <= 'Z'; c++) {
//                         if (c != exclude_char) {
//                             regex += c;
//                         }
//                     }
//                 } else {
//                     // Include all characters
//                     regex += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//                 }
//                 regex += ']';
//             }

//             return regex;
//         }
//     }

//     return "-1";
// }