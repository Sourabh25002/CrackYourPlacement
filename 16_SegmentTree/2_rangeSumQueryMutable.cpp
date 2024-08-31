#include <bits/stdc++.h>
using namespace std;

class NumArray
{
private:
  vector<int> nums;
  vector<int> BIT;
  int n;

  // Helper function to update the BIT
  void updateBIT(int index, int delta)
  {
    for (++index; index <= n; index += index & -index)
    {
      BIT[index] += delta;
    }
  }

  // Helper function to get prefix sum from BIT
  int getSum(int index)
  {
    int sum = 0;
    for (++index; index > 0; index -= index & -index)
    {
      sum += BIT[index];
    }
    return sum;
  }

public:
  // Constructor to initialize the BIT and the nums array
  NumArray(vector<int> &nums) : nums(nums), n(nums.size()), BIT(nums.size() + 1, 0)
  {
    for (int i = 0; i < n; ++i)
    {
      updateBIT(i, nums[i]);
    }
  }

  // Function to update the value at index
  void update(int index, int val)
  {
    int old_val = nums[index];
    int delta = val - old_val;
    nums[index] = val;
    updateBIT(index, delta);
  }

  // Function to get the sum from left to right inclusive
  int sumRange(int left, int right)
  {
    return getSum(right) - getSum(left - 1);
  }
};

int main()
{
  // Example usage
  vector<int> nums = {1, 3, 5};
  NumArray numArray(nums);

  cout << numArray.sumRange(0, 2) << endl; // Output: 9
  numArray.update(1, 2);
  cout << numArray.sumRange(0, 2) << endl; // Output: 8

  return 0;
}

/*
Time Complexity:
- Initialization: O(n * log(n))
- Update: O(log(n))
- SumRange: O(log(n))

Space Complexity: O(n)
*/
