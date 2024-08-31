#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int solveWordWrap(vector<int> nums, int k)
  {
    int n = nums.size();
    vector<int> dp(n, INT_MAX); // dp array to store the minimum cost
    vector<int> cost(n, 0);     // array to store the cost of each line

    for (int i = n - 1; i >= 0; i--)
    {
      int length = -1;
      for (int j = i; j < n; j++)
      {
        length += nums[j] + 1;
        if (length > k)
          break;

        int extraSpaces = k - length;
        int currCost = (j == n - 1) ? 0 : extraSpaces * extraSpaces + dp[j + 1];
        dp[i] = min(dp[i], currCost);
      }
    }

    return dp[0];
  }
};

int main()
{
  Solution solution;

  vector<int> nums1 = {3, 2, 2, 5};
  int k1 = 6;
  cout << "Output: " << solution.solveWordWrap(nums1, k1) << endl;

  vector<int> nums2 = {3, 2, 2};
  int k2 = 4;
  cout << "Output: " << solution.solveWordWrap(nums2, k2) << endl;

  return 0;
}

/*
Time Complexity: O(n^2)
Space Complexity: O(n)
*/
