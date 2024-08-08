#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool canJump(vector<int> &nums)
  {
    int targetNumIndex = nums.size() - 1; // Initialize the target to the last index

    // Traverse the array from the second last element to the first
    for (int i = nums.size() - 2; i >= 0; i--)
    {
      // If we can reach or go beyond the target index from the current index
      if (targetNumIndex <= i + nums[i])
      {
        targetNumIndex = i; // Update the target to the current index
      }
    }

    // Check if we managed to reach the first index (starting point)
    return targetNumIndex == 0;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1 = {2, 3, 1, 1, 4};
  cout << (sol.canJump(nums1) ? "true" : "false") << endl; // Output: true

  // Example 2
  vector<int> nums2 = {3, 2, 1, 0, 4};
  cout << (sol.canJump(nums2) ? "true" : "false") << endl; // Output: false

  return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)