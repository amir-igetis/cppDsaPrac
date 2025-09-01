#include <bits/stdc++.h>
using namespace std;

vector<string> fullJustify(vector<string> &words, int maxWidth)
{
    vector<string> result;
    int i = 0;

    while (i < words.size())
    {
        int lineLen = words[i].size();
        int j = i + 1;

        // Try to fit as many words as possible in this line
        while (j < words.size() && lineLen + words[j].size() + (j - i) <= maxWidth)
        {
            lineLen += words[j].size();
            j++;
        }

        int spaces = maxWidth - lineLen;
        int numWords = j - i;

        string line;

        // If it's the last line or only one word in the line
        if (j == words.size() || numWords == 1)
        {
            for (int k = i; k < j; ++k)
            {
                line += words[k];
                if (k != j - 1)
                    line += " ";
            }
            line += string(maxWidth - line.size(), ' ');
        }
        else
        {
            int spaceBetween = spaces / (numWords - 1);
            int extra = spaces % (numWords - 1);

            for (int k = i; k < j; ++k)
            {
                line += words[k];
                if (k != j - 1)
                {
                    int spaceToAdd = spaceBetween + (extra-- > 0 ? 1 : 0);
                    line += string(spaceToAdd, ' ');
                }
            }
        }

        result.push_back(line);
        i = j;
    }

    return result;
}

int main()
{
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> result = fullJustify(words, maxWidth);

    for (const string &line : result)
    {
        cout << '"' << line << '"' << endl;
    }

    return 0;
}
