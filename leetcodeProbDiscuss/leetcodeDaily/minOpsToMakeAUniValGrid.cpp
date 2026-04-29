#include <bits/stdc++.h>
using namespace std;

// two pointers tc O(mn * log mn) sc O(mn)

int minOperationsII(vector<vector<int>> &grid, int x)
{
    // Initialize an empty array to store all numbers from the grid
    vector<int> numsArray;
    int result = 0;

    // Flatten the grid into numsArray
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            // If any element has a different remainder than the first
            // element, it is impossible to make all elements equal, so
            // return -1
            if (grid[row][col] % x != grid[0][0] % x)
                return -1;
            numsArray.push_back(grid[row][col]);
        }
    }

    // Sort numsArray in non-decreasing order to facilitate efficient
    // operations
    sort(numsArray.begin(), numsArray.end());

    int length = numsArray.size();
    int prefixIndex = 0;
    int suffixIndex = length - 1;

    // Gradually move prefixIndex and suffixIndex towards the middle
    while (prefixIndex < suffixIndex)
    {
        // If the prefix of equal elements is shorter than the suffix
        if (prefixIndex < length - suffixIndex - 1)
        {
            // Calculate the number of operations required to extend the
            // prefix
            int prefixOperations =
                (prefixIndex + 1) *
                (numsArray[prefixIndex + 1] - numsArray[prefixIndex]) / x;

            result += prefixOperations;
            // Move the prefix index forward
            prefixIndex++;
        }
        else
        {
            // Calculate the number of operations required to extend the
            // suffix
            int suffixOperations =
                (length - suffixIndex) *
                (numsArray[suffixIndex] - numsArray[suffixIndex - 1]) / x;

            result += suffixOperations;
            // Move the suffix index backward
            suffixIndex--;
        }
    }

    return result;
}

// prefix and suffix sum tc O(mn * log mn) sc O(mn)

int minOperationsI(vector<vector<int>> &grid, int x)
{
    // Initialize an empty array to store all numbers
    vector<int> numsArray;
    int result = INT_MAX;

    // Flatten the grid into numsArray and check if all elements have the
    // same remainder when divided by x
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            // If remainder of any element doesn't match the first element,
            // return -1
            if (grid[row][col] % x != grid[0][0] % x)
                return -1;
            numsArray.push_back(grid[row][col]);
        }
    }

    // Sort numsArray in non-decreasing order to easily calculate operations
    sort(numsArray.begin(), numsArray.end());

    int length = numsArray.size();
    vector<int> prefixSum(length, 0);
    vector<int> suffixSum(length, 0);

    // Calculate the prefix sum up to each index (excluding the current
    // element)
    for (int index = 1; index < length; index++)
    {
        prefixSum[index] = prefixSum[index - 1] + numsArray[index - 1];
    }

    // Calculate the suffix sum from each index (excluding the current
    // element)
    for (int index = length - 2; index >= 0; index--)
    {
        suffixSum[index] = suffixSum[index + 1] + numsArray[index + 1];
    }

    // Iterate through numsArray to calculate the number of operations for
    // each potential common value
    for (int index = 0; index < length; index++)
    {
        int leftOperations =
            (numsArray[index] * index - prefixSum[index]) / x;

        int rightOperations =
            (suffixSum[index] - numsArray[index] * (length - index - 1)) /
            x;

        // Update the result with the minimum operations needed
        result = min(result, leftOperations + rightOperations);
    }

    return result;
}

// sorting and median tc O(mn * log mn) sc O(mn)

int minOperations(vector<vector<int>> &grid, int x)
{
    vector<int> numsArray;
    int result = 0;

    // Flatten the grid into numsArray
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            numsArray.push_back(grid[row][col]);
        }
    }

    int length = numsArray.size();

    // Partially sorts the array so that the median element is placed at the
    // middle index
    nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                numsArray.end());

    // Store the median element as the final common value to make all
    // elements equal to
    int finalCommonNumber = numsArray[length / 2];

    for (int number : numsArray)
    {
        // If the remainder when divided by x is different for any number,
        // return -1
        if (number % x != finalCommonNumber % x)
            return -1;
        // Add the number of operations required to make the current number
        // equal to finalCommonNumber
        result += abs(finalCommonNumber - number) / x;
    }

    return result;
}

int main()
{

    vector<vector<int>> grid = {{2, 4}, {6, 8}};
    int x = 2;
    cout << minOperations(grid, x) << endl;

    return 0;
}