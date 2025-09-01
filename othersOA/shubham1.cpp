#include <bits/stdc++.h>
using namespace std;

string toLowerCase(const string &s)
{
    string result = s;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int countSpamWords(const string &subject, const vector<string> &spamKeywords)
{
    unordered_map<string, int> wordCount;
    stringstream ss(subject);
    string word;
    while (ss >> word)
    {
        wordCount[word]++;
    }

    int spamCount = 0;
    for (const string &spamWord : spamKeywords)
    {
        if (wordCount.find(spamWord) != wordCount.end())
        {
            spamCount += wordCount[spamWord];
        }
    }
    return spamCount;
}

vector<string> detectSpamEmails(vector<string> &applicantSubjects, vector<string> &spamKeywords)
{
    vector<string> result;

    for (string &keyword : spamKeywords)
    {
        keyword = toLowerCase(keyword);
    }

    for (string &subject : applicantSubjects)
    {
        string lowerSubject = toLowerCase(subject);

        int spamWordCount = countSpamWords(lowerSubject, spamKeywords);

        if (spamWordCount >= 2)
        {
            result.push_back("spam");
        }
        else
        {
            result.push_back("not_spam");
        }
    }
    return result;
}

int main()
{
    vector<string> applicantSubjects = {"Sales Job Inquiry", "Quick Money Opportunity", "Earn Cash Fast", "Quick offer requested"};
    vector<string> spamKeywords = {"quick", "money", "earn", "cash"};

    vector<string> result = detectSpamEmails(applicantSubjects, spamKeywords);

    for (const string &res : result)
    {
        cout << res << endl;
    }

    return 0;
}
