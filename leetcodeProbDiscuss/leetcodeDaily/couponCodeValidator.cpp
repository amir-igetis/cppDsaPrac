#include <bits/stdc++.h>
using namespace std;

vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
{
    vector<string> e, g, p, r;
    for (int i = 0; i < isActive.size(); i++)
    {
        if (!isActive[i])
            continue;
        string &bl = businessLine[i];
        if (bl != "electronics" &&
            bl != "grocery" && bl != "pharmacy" && bl != "restaurant")
            continue;

        if (code[i].empty())
            continue;

        bool ok = true;

        for (char ch : code[i])
        {
            if (!isalnum(ch) && ch != '_')
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;

        if (bl[0] == 'e')
            e.push_back(code[i]);
        if (bl[0] == 'g')
            g.push_back(code[i]);
        if (bl[0] == 'p')
            p.push_back(code[i]);
        if (bl[0] == 'r')
            r.push_back(code[i]);
    }
    sort(e.begin(), e.end());
    sort(g.begin(), g.end());
    sort(p.begin(), p.end());
    sort(r.begin(), r.end());

    vector<string> res;

    res.insert(res.end(), e.begin(), e.end());
    res.insert(res.end(), g.begin(), g.end());
    res.insert(res.end(), p.begin(), p.end());
    res.insert(res.end(), r.begin(), r.end());

    return res;
}

int main()
{
    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"},
                   businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};

    vector<string> ans = validateCoupons(code, businessLine, isActive);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}