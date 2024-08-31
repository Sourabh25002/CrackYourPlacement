#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int search(vector<int> &nums, int target)
  {
    int n = nums.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
      int mid = low + (high - low) / 2;

      if (nums[mid] == target)
        return mid;
      else if (nums[low] <= nums[mid])
      {
        if (nums[low] <= target && target < nums[mid])
          high = mid - 1;
        else
          low = mid + 1;
      }
      else
      {
        if (nums[mid] < target && target <= nums[high])
          low = mid + 1;
        else
          high = mid - 1;
      }
    }

    return -1;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  Solution sol;

  vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
  int target1 = 0;
  cout << sol.search(nums1, target1) << endl; // Output: 4

  vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
  int target2 = 3;
  cout << sol.search(nums2, target2) << endl; // Output: -1

  vector<int> nums3 = {1};
  int target3 = 0;
  cout << sol.search(nums3, target3) << endl; // Output: -1

  return 0;
}

/*
Time Complexity: O(log n), due to binary search.
Space Complexity: O(1), constant space used for variables.
*/
