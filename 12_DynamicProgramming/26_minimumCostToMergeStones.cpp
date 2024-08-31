#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int mergeStones(vector<int> &stones, int k)
  {
    int n = stones.size();
    if ((n - 1) % (k - 1) != 0)
      return -1; // If it's impossible to merge into one pile

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<int>> prefixSum(n, vector<int>(n, 0));

    // Compute prefix sums
    for (int i = 0; i < n; ++i)
    {
      prefixSum[i][i] = stones[i];
      for (int j = i + 1; j < n; ++j)
      {
        prefixSum[i][j] = prefixSum[i][j - 1] + stones[j];
      }
    }

    // Initialize base cases: merge k piles
    for (int i = 0; i < n - k + 1; ++i)
    {
      dp[i][i + k - 1] = prefixSum[i][i + k - 1];
    }

    // Solve using dynamic programming
    for (int len = k; len <= n; ++len)
    {
      for (int i = 0; i + len - 1 < n; ++i)
      {
        int j = i + len - 1;
        for (int m = i; m < j; m += k - 1)
        {
          dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
        }
        if ((j - i) % (k - 1) == 0)
        {
          dp[i][j] += prefixSum[i][j];
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  Solution sol;

  vector<int> stones1 = {3, 2, 4, 1};
  int k1 = 2;
  cout << "Minimum cost to merge stones (Example 1): " << sol.mergeStones(stones1, k1) << endl; // Output: 20

  vector<int> stones2 = {3, 2, 4, 1};
  int k2 = 3;
  cout << "Minimum cost to merge stones (Example 2): " << sol.mergeStones(stones2, k2) << endl; // Output: -1

  vector<int> stones3 = {3, 5, 1, 2, 6};
  int k3 = 3;
  cout << "Minimum cost to merge stones (Example 3): " << sol.mergeStones(stones3, k3) << endl; // Output: 25

  return 0;
}

/*
Time Complexity: O(n^3), where n is the number of stones. The complexity arises from the three nested loops for computing dp table values.
Space Complexity: O(n^2), due to the dp and prefixSum tables.
*/
