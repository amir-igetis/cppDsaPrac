#include <bits/stdc++.h>
using namespace std;

//    single pass with freq arr tc and sc O(n)

vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> prefixCommonArr(n);
    vector<int> freq(n + 1);
    int commonCount = 0;
    for (int currIdx = 0; currIdx < n; currIdx++)
    {
        freq[A[currIdx]] += 1;
        if (freq[A[currIdx]] == 2)
            commonCount++;
        freq[B[currIdx]] += 1;
        if (freq[B[currIdx]] == 2)
            commonCount++;

        prefixCommonArr[currIdx] = commonCount;
    }
    return prefixCommonArr;
}

int main()
{
    vector<int> A = {1, 3, 2, 4}, B = {3, 1, 2, 4};
    vector<int> ans = findThePrefixCommonArray(A, B);
    for (auto &i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}