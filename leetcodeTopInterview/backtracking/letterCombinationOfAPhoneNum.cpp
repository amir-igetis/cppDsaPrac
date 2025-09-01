#include <bits/stdc++.h>
using namespace std;

vector<string> res;
vector<string> mapping = {
    "",     // 0
    "",     // 1
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

void backtrack(string &digits, int index, string curr)
{
    if (index == digits.size())
    {
        res.push_back(curr);
        return;
    }

    string letters = mapping[digits[index] - '0'];
    for (char ch : letters)
        backtrack(digits, index + 1, curr + ch);
}

vector<string> letterCombinations(string digits)
{
    if (digits.empty())
        return {};
    backtrack(digits, 0, "");
    return res;
}

// using map

unordered_map<char, string> phoneMap = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

void backtrackI(vector<string> &result, string &current, const string &digits, int index)
{
    if (index == digits.size())
    {
        result.push_back(current);
        return;
    }

    string letters = phoneMap[digits[index]];
    for (char c : letters)
    {
        current.push_back(c);
        backtrackI(result, current, digits, index + 1);
        current.pop_back(); // backtrack
    }
}

vector<string> letterCombinationsI(string digits)
{
    vector<string> result;
    if (digits.empty())
        return result;

    string current;
    backtrackI(result, current, digits, 0);
    return result;
}

int main()
{

    string digits = "23";

    vector<string> ans = letterCombinationsI(digits);

    for (string i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}