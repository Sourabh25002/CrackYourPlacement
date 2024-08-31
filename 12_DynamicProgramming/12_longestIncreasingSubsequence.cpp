#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int lengthOfLIS(vector<int> &nums)
  {
    if (nums.empty())
      return 0;

    vector<int> dp(nums.size(), 1);
    int maxLength = 1;

    for (int i = 1; i < nums.size(); ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (nums[i] > nums[j])
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
  cout << "Output for nums1: " << sol.lengthOfLIS(nums1) << endl; // Output: 4

  vector<int> nums2 = {0, 1, 0, 3, 2, 3};
  cout << "Output for nums2: " << sol.lengthOfLIS(nums2) << endl; // Output: 4

  vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
  cout << "Output for nums3: " << sol.lengthOfLIS(nums3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
