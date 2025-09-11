#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string sortVowels(string s)
{
    vector<char> vow;
    vector<int> pos;

    for (int i = 0; i < s.size(); i++)
    {
        if (isVowel(s[i]))
        {
            vow.push_back(s[i]);
            pos.push_back(i);
        }
    }
    sort(vow.begin(), vow.end());

    for (int i = 0; i < pos.size(); i++)
    {
        s[pos[i]] = vow[i];
    }

    return s;
}

int main()
{

    string s = "lEetcOde";

    cout << sortVowels(s) << endl;

    return 0;
}