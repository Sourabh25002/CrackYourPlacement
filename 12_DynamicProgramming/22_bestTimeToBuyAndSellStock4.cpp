#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxProfit(int k, vector<int> &prices)
  {
    int n = prices.size();
    if (n == 0)
      return 0;

    if (k >= n / 2)
    {
      // If k is large enough, perform as many transactions as possible
      int maxProfit = 0;
      for (int i = 1; i < n; ++i)
      {
        if (prices[i] > prices[i - 1])
        {
          maxProfit += prices[i] - prices[i - 1];
        }
      }
      return maxProfit;
    }

    // DP approach
    vector<vector<int>> dp(k + 1, vector<int>(n, 0));

    for (int i = 1; i <= k; ++i)
    {
      int maxDiff = -prices[0];
      for (int j = 1; j < n; ++j)
      {
        dp[i][j] = max(dp[i][j - 1], prices[j] + maxDiff);
        maxDiff = max(maxDiff, dp[i - 1][j] - prices[j]);
      }
    }

    return dp[k][n - 1];
  }
};

int main()
{
  Solution sol;

  // Example 1
  int k1 = 2;
  vector<int> prices1 = {2, 4, 1};
  cout << "Output for k1, prices1: " << sol.maxProfit(k1, prices1) << endl; // Output: 2

  // Example 2
  int k2 = 2;
  vector<int> prices2 = {3, 2, 6, 5, 0, 3};
  cout << "Output for k2, prices2: " << sol.maxProfit(k2, prices2) << endl; // Output: 7

  return 0;
}

/*
Time Complexity: O(k * n), where n is the number of days and k is the number of transactions.
Space Complexity: O(k * n), due to the DP table used to store intermediate results.
*/
