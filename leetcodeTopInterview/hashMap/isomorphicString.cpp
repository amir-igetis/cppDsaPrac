#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> sToT, tToS;

    for (int i = 0; i < s.size(); i++)
    {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT.count(sChar))
        {
            if (sToT[sChar] != tChar)
                return false;
        }
        else
            sToT[sChar] = tChar;

        if (tToS.count(tChar))
        {
            if (tToS[tChar] != sChar)
                return false;
        }
        else
            tToS[tChar] = sChar;
    }
    return true;
}

bool isIsomorphicI(string s, string t)
{

    if (s.size() != t.size())
        return false;

    vector<int> sToT(256), tToS(256);

    for (int i = 0; i < s.size(); i++)
    {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT[sChar] != 0 && sToT[sChar] != tChar)
            return false;

        if (tToS[tChar] != 0 && tToS[tChar] != sChar)
            return false;

        sToT[sChar] = tChar;
        tToS[tChar] = sChar;
    }
    return true;
}

bool isIsomorphicII(string s, string t)
{

    if (s.size() != t.size())
        return false;

    vector<int> sToT(256), tToS(256);

    for (int i = 0; i < s.size(); i++)
    {
        char sChar = s[i];
        char tChar = t[i];

        if (sToT[sChar] != 0 && sToT[sChar] != tChar)
            return false;
        else
            sToT[sChar] = tChar;

        if (tToS[tChar] != 0 && tToS[tChar] != sChar)
            return false;
        else
            tToS[tChar] = sChar;
    }
    return true;
}

int main()
{

    string s = "egg", t = "add";

    cout << isIsomorphic(s, t) << endl;

    return 0;
}