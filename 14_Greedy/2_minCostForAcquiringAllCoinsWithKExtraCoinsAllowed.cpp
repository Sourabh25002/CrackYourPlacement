#include <bits/stdc++.h>
using namespace std;

int minCostToAcquireCoins(vector<int> &coins, int k)
{
  // Sort the coins in ascending order
  sort(coins.begin(), coins.end());

  int n = coins.size();
  int coinsToBuy = ceil((double)n / (k + 1));
  int minCost = 0;

  // Add the cost of the smallest coinsToBuy coins
  for (int i = 0; i < coinsToBuy; i++)
  {
    minCost += coins[i];
  }

  return minCost;
}

int main()
{
  vector<int> coins1 = {100, 20, 50, 10, 2, 5};
  int k1 = 3;
  cout << "Example 1 Output: " << minCostToAcquireCoins(coins1, k1) << endl; // Output: 7

  vector<int> coins2 = {1, 2, 5, 10, 20, 50};
  int k2 = 3;
  cout << "Example 2 Output: " << minCostToAcquireCoins(coins2, k2) << endl; // Output: 3

  return 0;
}

/*
Time Complexity: O(n log n), where n is the number of coins (for sorting).
Space Complexity: O(1), as we are using only a constant amount of extra space.
*/
