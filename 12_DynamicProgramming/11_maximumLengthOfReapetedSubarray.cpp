#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findLength(vector<int> &nums1, vector<int> &nums2)
  {
    int m = nums1.size();
    int n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (nums1[i - 1] == nums2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          maxLength = max(maxLength, dp[i][j]);
        }
      }
    }

    return maxLength;
  }
};

int main()
{
  Solution sol;

  vector<int> nums1 = {1, 2, 3, 2, 1};
  vector<int> nums2 = {3, 2, 1, 4, 7};
  cout << "Output for nums1 and nums2: " << sol.findLength(nums1, nums2) << endl; // Output: 3

  vector<int> nums1_2 = {0, 0, 0, 0, 0};
  vector<int> nums2_2 = {0, 0, 0, 0, 0};
  cout << "Output for nums1_2 and nums2_2: " << sol.findLength(nums1_2, nums2_2) << endl; // Output: 5

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
