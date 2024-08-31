#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProduct(vector<int> &nums)
  {
    int n = nums.size();
    int maxProduct = nums[0];
    int currentMax = nums[0];
    int currentMin = nums[0];

    for (int i = 1; i < n; ++i)
    {
      if (nums[i] < 0)
      {
        swap(currentMax, currentMin);
      }
      currentMax = max(nums[i], currentMax * nums[i]);
      currentMin = min(nums[i], currentMin * nums[i]);
      maxProduct = max(maxProduct, currentMax);
    }

    return maxProduct;
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {2, 3, -2, 4};
  vector<int> nums2 = {-2, 0, -1};
  vector<int> nums3 = {-2, 3, -4};

  cout << "Maximum product subarray for nums1: " << sol.maxProduct(nums1) << endl; // Output: 6
  cout << "Maximum product subarray for nums2: " << sol.maxProduct(nums2) << endl; // Output: 0
  cout << "Maximum product subarray for nums3: " << sol.maxProduct(nums3) << endl; // Output: 24

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/
