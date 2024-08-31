#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxCoins(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> balloons(n + 2, 1);
    for (int i = 0; i < n; ++i)
    {
      balloons[i + 1] = nums[i];
    }

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int length = 1; length <= n; ++length)
    {
      for (int left = 1; left <= n - length + 1; ++left)
      {
        int right = left + length - 1;
        for (int i = left; i <= right; ++i)
        {
          dp[left][right] = max(dp[left][right], dp[left][i - 1] + dp[i + 1][right] + balloons[left - 1] * balloons[i] * balloons[right + 1]);
        }
      }
    }

    return dp[1][n];
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {3, 1, 5, 8};
  cout << "Max Coins (Example 1): " << sol.maxCoins(nums1) << endl; // Output: 167

  vector<int> nums2 = {1, 5};
  cout << "Max Coins (Example 2): " << sol.maxCoins(nums2) << endl; // Output: 10

  return 0;
}

/*
Time Complexity: O(n^3), where n is the number of balloons. This is due to the triple nested loops.
Space Complexity: O(n^2), due to the DP table used to store results of subproblems.
*/
