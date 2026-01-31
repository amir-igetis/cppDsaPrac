#include <bits/stdc++.h>
using namespace std;

string reverseByType(string s)
{
    map<int, char> letter;
    map<int, char> spCh;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            letter[i] = s[i];
        else
            spCh[i] = s[i];
    }

    vector<char> lett;
    for (auto &i : letter)
        lett.push_back(i.second);

    reverse(lett.begin(), lett.end());
    vector<char> sp;
    for (auto &i : spCh)
        sp.push_back(i.second);
    reverse(sp.begin(), sp.end());

    int l = 0, st = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (letter.count(i))
            s[i] = lett[l++];
        else
            s[i] = sp[st++];
    }
    return s;
}

int main()
{
    string s = ")ebc#da@f(";
    cout << reverseByType(s) << endl;

    return 0;
}