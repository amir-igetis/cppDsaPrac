#include <bits/stdc++.h>
using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> valToIndex;
    vector<int> nums;

public:
    RandomizedSet() {}

    bool insert(int val)
    {
        if (valToIndex.count(val))
            return false;
        nums.push_back(val);
        valToIndex[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val)
    {
        if (!valToIndex.count(val))
            return false;
        int idx = valToIndex[val];
        int last = nums.back();

        nums[idx] = last;
        valToIndex[last] = idx;

        nums.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }
};

int main()
{
    RandomizedSet randomSet;

    cout << randomSet.insert(1) << endl;   // true
    cout << randomSet.remove(2) << endl;   // false
    cout << randomSet.insert(2) << endl;   // true
    cout << randomSet.getRandom() << endl; // 1 or 2
    cout << randomSet.remove(1) << endl;   // true
    cout << randomSet.insert(2) << endl;   // false (already in set)
    cout << randomSet.getRandom() << endl; // 2
}