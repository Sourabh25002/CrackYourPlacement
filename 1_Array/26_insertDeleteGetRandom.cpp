#include <bits/stdc++.h>
using namespace std;

class RandomizedCollection
{
public:
  /** Initialize your data structure here. */
  RandomizedCollection()
  {
    // No initialization needed since we're using vectors and unordered_map
  }

  /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
  bool insert(int val)
  {
    // Check if the element is new to the collection
    bool result = m.find(val) == m.end();

    // Store the index of the new element in the map and add the element to the nums vector
    m[val].push_back(nums.size());
    nums.push_back({val, m[val].size() - 1});

    return result;
  }

  /** Removes a value from the collection. Returns true if the collection contained the specified element. */
  bool remove(int val)
  {
    // Check if the element exists in the collection
    bool result = m.find(val) != m.end();
    if (result)
    {
      // Get the last element in the nums vector
      auto last = nums.back();
      // Move the last element to the position of the element to remove
      m[last.first][last.second] = m[val].back();
      nums[m[val].back()] = last;
      // Remove the element from the map and nums vector
      m[val].pop_back();
      if (m[val].empty())
        m.erase(val);
      nums.pop_back();
    }
    return result;
  }

  /** Get a random element from the collection. */
  int getRandom()
  {
    // Return a random element from the nums vector
    return nums[rand() % nums.size()].first;
  }

private:
  vector<pair<int, int>> nums;       // Vector to store elements with their indices
  unordered_map<int, vector<int>> m; // Map to store the indices of each element in nums
};

int main()
{
  RandomizedCollection randomizedCollection;

  // Test Example 1
  cout << boolalpha << randomizedCollection.insert(1) << endl; // true
  cout << boolalpha << randomizedCollection.insert(1) << endl; // false
  cout << boolalpha << randomizedCollection.insert(2) << endl; // true
  cout << randomizedCollection.getRandom() << endl;            // 1 or 2 (1 with 2/3 probability)
  cout << boolalpha << randomizedCollection.remove(1) << endl; // true
  cout << randomizedCollection.getRandom() << endl;            // 1 or 2 (equally likely)

  return 0;
}

/*
Time Complexity:
- `insert(int val)`: Average O(1) because we append to a vector and add to a map, both O(1) operations.
- `remove(int val)`: Average O(1) because we swap and pop in a vector and update the map, both O(1) operations.
- `getRandom()`: O(1) because it retrieves an element from a vector using a random index.

Space Complexity:
- O(n) where n is the number of elements inserted in the collection. We use a vector to store the elements and an unordered_map to track their indices.
*/
