#include <bits/stdc++.h>
using namespace std;
//  Complete the max_product_of_four function below.
// The function is expected to return an LONG INTEGER.
// The Function accepts INTEGER ARRAY arr as parameter.

long max_product_of_four(vector<int> &arr)
{
    // Write your code here
    // int n = arr.size();
    // if (n < 4)
    // {
    //     return -1; // If less than 4 elements, no valid product
    // }

    // // Sort the array
    // sort(arr.begin(), arr.end());

    // // Calculate the possible maximum products
    // long long pro1 = (long long)arr[n - 1] * arr[n - 2] * arr[n - 3] * arr[n - 4]; // Largest 4 elements
    // long long pro2 = (long long)arr[0] * arr[1] * arr[n - 1] * arr[n - 2];         // Smallest 2 and largest 2
    // long long pro3 = (long long)arr[0] * arr[1] * arr[2] * arr[3];
    // return max(pro1, max(pro2, pro3));

    set<int> unique(arr.begin(), arr.end());
    vector<int> uniqueArr(unique.begin(), unique.end());

    int n = uniqueArr.size();
    if (n < 4)
        return -1;

    sort(uniqueArr.begin(), uniqueArr.end());
    long long pro1 = (long long)uniqueArr[n - 1] * uniqueArr[n - 2] * uniqueArr[n - 3] * uniqueArr[n - 4];
    long long pro2 = (long long)uniqueArr[0] * uniqueArr[1] * uniqueArr[n - 1] * uniqueArr[n - 2];
    long long pro3 = (long long)uniqueArr[0] * uniqueArr[1] * uniqueArr[2] * uniqueArr[3];
    return max(pro1, max(pro2, pro3));
}

string palin(string str)
{
    unordered_map<char, int> mp;
    for (char ch : str)
        mp[ch]++;

    int odd = 0;
    for (const auto &pair : mp)
    {
        if (pair.second % 2 != 0)
            odd++;
    }
    if (odd > 1)
        return "not poss";
    return "poss";
}

int main()
{

    // vector<int> arr = {-100000, -200000, 300000, 400000, 5, 6};

    // vector<int> arr = {7, 2, 3, -1, 7, -6, 4, 0};
    vector<int> arr = {5, -10, -10, 5, 3, 2};
    cout << max_product_of_four(arr) << endl;
    return 0;
}

/*


Write a function to find the maximum product by multiplying 4 integers from an array

Input Format
The first line contains an integer N
Next N lines contain an integer each, the elements of the array A

Constraints
Consider both positive and negative integers
2<=N<=10^5
1 <= A[i] <= 10^9

Output Format
Print the single integer the maximum possible
product

*/

/*
Problem Statement
You are given a string containing only lowercase letters. Your task is to determine if it's possible to rearrange the characters in the string to form a palindrome.
A palindrome is a word that reads the same forwards and backwards
Input Format
• Input will be a random string
• The string contains only lowercase English alphabets.
Constraints
• String with characters N
•N> 5
• N < 10^5
Output Format
• Output will be
1. Possible to form a palindrome
2. Not possible to form a palindrome
*/


