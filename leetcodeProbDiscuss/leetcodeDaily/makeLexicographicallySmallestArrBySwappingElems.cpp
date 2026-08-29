#include <bits/stdc++.h>
using namespace std;

// sorting + grouping

/// Let N be the size of nums.
///
/// Time Complexity: O(N⋅logN)
///
/// Sorting nums takes O(N⋅logN) time. Iterating through each element in sortedNums and updating our two maps takes O(N) time. Iterating through nums to overwrite its values with the sorted list values in each group takes a total of O(N) time. Thus, the total time complexity is O(N⋅logN).
///
/// Space Complexity: O(N+S_n)≈O(N)
///
/// Both our maps have a space complexity of N. The space complexity used for sorting nums depends on the language of implementation:
///
/// In Java, Arrays.sort() is implemented using a variant of the Quick Sort algorithm which has a space complexity of O(logN).
/// In C++, the sort() function is implemented as a hybrid of Quick Sort, Heap Sort, and Insertion Sort, with a worst-case space complexity of O(logN).
/// In Python, the sort() method sorts a list using the Timsort algorithm which is a combination of Merge Sort and Insertion Sort and has a space complexity of O(N).
///
/// Thus, the total space complexity is O(N+S_n)≈O(N).
vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
{
    vector<int> numsSorted(nums);
    sort(numsSorted.begin(), numsSorted.end());

    int currGroup = 0;
    unordered_map<int, int> numToGroup;
    numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

    unordered_map<int, list<int>> groupToList;
    groupToList.insert(
        pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

    for (int i = 1; i < nums.size(); i++)
    {
        if (abs(numsSorted[i] - numsSorted[i - 1]) > limit)
        {
            // new group
            currGroup++;
        }

        // assign current element to group
        numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

        // add element to sorted group list
        if (groupToList.find(currGroup) == groupToList.end())
        {
            groupToList[currGroup] = list<int>();
        }
        groupToList[currGroup].push_back(numsSorted[i]);
    }

    // iterate through input and overwrite each element with the next
    // element in its corresponding group
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];
        int group = numToGroup[num];
        nums[i] = *groupToList[group].begin();
        groupToList[group].pop_front();
    }

    return nums;
}

int main()
{
    vector<int> nums = {1, 5, 3, 9, 8};
    int limit = 2;

    vector<int> result = lexicographicallySmallestArray(nums, limit);
    for (auto &i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}