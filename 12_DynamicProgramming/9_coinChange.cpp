#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i)
    {
      for (int coin : coins)
      {
        if (i >= coin && dp[i - coin] != INT_MAX)
        {
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
  }
};

int main()
{
  Solution sol;

  vector<int> coins1 = {1, 2, 5};
  int amount1 = 11;
  cout << "Output for coins1: " << sol.coinChange(coins1, amount1) << endl; // Output: 3

  vector<int> coins2 = {2};
  int amount2 = 3;
  cout << "Output for coins2: " << sol.coinChange(coins2, amount2) << endl; // Output: -1

  vector<int> coins3 = {1};
  int amount3 = 0;
  cout << "Output for coins3: " << sol.coinChange(coins3, amount3) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(amount * coins.length)
Space Complexity: O(amount)
*/
