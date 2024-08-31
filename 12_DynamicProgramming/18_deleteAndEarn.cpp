#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int deleteAndEarn(vector<int> &nums)
  {
    // Find the maximum value in nums
    int maxNum = *max_element(nums.begin(), nums.end());

    // Create a vector to store the sum of points for each number
    vector<int> points(maxNum + 1, 0);
    for (int num : nums)
    {
      points[num] += num;
    }

    // Initialize dp array
    vector<int> dp(maxNum + 1, 0);
    dp[1] = points[1];

    // Fill dp array
    for (int i = 2; i <= maxNum; ++i)
    {
      dp[i] = max(dp[i - 1], dp[i - 2] + points[i]);
    }

    return dp[maxNum];
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> nums1 = {3, 4, 2};
  cout << "Output for nums1: " << sol.deleteAndEarn(nums1) << endl; // Output: 6

  // Example 2
  vector<int> nums2 = {2, 2, 3, 3, 3, 4};
  cout << "Output for nums2: " << sol.deleteAndEarn(nums2) << endl; // Output: 9

  return 0;
}

/*
Time Complexity: O(n + k) where n is the length of nums and k is the maximum number in nums
Space Complexity: O(k) for the points and dp arrays, where k is the maximum number in nums
*/
