#include <bits/stdc++.h>
using namespace std;

class BIT
{
private:
  vector<int> bit;
  int n;

  // Helper function to update the BIT
  void update(int index, int value)
  {
    for (++index; index <= n; index += index & -index)
    {
      bit[index] += value;
    }
  }

  // Helper function to get the prefix sum from BIT
  int query(int index)
  {
    int sum = 0;
    for (++index; index > 0; index -= index & -index)
    {
      sum += bit[index];
    }
    return sum;
  }

public:
  BIT(int size) : n(size)
  {
    bit.assign(size + 1, 0);
  }

  void update(int index, int value)
  {
    ::update(index, value);
  }

  int query(int index)
  {
    return ::query(index);
  }
};

vector<int> countSmaller(vector<int> &nums)
{
  vector<int> result(nums.size(), 0);
  vector<int> sorted_nums = nums;
  sort(sorted_nums.begin(), sorted_nums.end());
  sorted_nums.erase(unique(sorted_nums.begin(), sorted_nums.end()), sorted_nums.end());

  BIT bit(sorted_nums.size());

  for (int i = nums.size() - 1; i >= 0; --i)
  {
    int index = lower_bound(sorted_nums.begin(), sorted_nums.end(), nums[i]) - sorted_nums.begin();
    result[i] = bit.query(index - 1);
    bit.update(index, 1);
  }

  return result;
}

int main()
{
  vector<int> nums1 = {5, 2, 6, 1};
  vector<int> nums2 = {-1};
  vector<int> nums3 = {-1, -1};

  vector<int> result1 = countSmaller(nums1);
  vector<int> result2 = countSmaller(nums2);
  vector<int> result3 = countSmaller(nums3);

  cout << "Output for [5, 2, 6, 1]: ";
  for (int num : result1)
    cout << num << " ";
  cout << endl;

  cout << "Output for [-1]: ";
  for (int num : result2)
    cout << num << " ";
  cout << endl;

  cout << "Output for [-1, -1]: ";
  for (int num : result3)
    cout << num << " ";
  cout << endl;

  return 0;
}

/*
Time Complexity:
- Sorting: O(n log n)
- BIT Operations: O(n log n)
Overall: O(n log n)

Space Complexity:
- BIT: O(n)
- Sorted Array: O(n)
Overall: O(n)
*/
