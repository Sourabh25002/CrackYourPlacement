
#include <bits/stdc++.h>
using namespace std;

long getAns(long *Arr, int ind, int buy, int n, vector<vector<long>> &dp)
{
  if (ind == n)
  {
    return 0;
  }

  if (dp[ind][buy] != -1)
  {
    return dp[ind][buy];
  }

  long profit = 0;

  if (buy == 0)
  {
    profit = max(0 + getAns(Arr, ind + 1, 0, n, dp), -Arr[ind] + getAns(Arr, ind + 1, 1, n, dp));
  }

  if (buy == 1)
  {
    profit = max(0 + getAns(Arr, ind + 1, 1, n, dp), Arr[ind] + getAns(Arr, ind + 1, 0, n, dp));
  }

  return dp[ind][buy] = profit;
}

long getMaximumProfit(long *Arr, int n)
{
  vector<vector<long>> dp(n, vector<long>(2, -1));

  if (n == 0)
  {
    return 0;
  }

  long ans = getAns(Arr, 0, 0, n, dp);
  return ans;
}

int main()
{
  int n = 6;
  long Arr[n] = {7, 1, 5, 3, 6, 4};

  cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n);

  return 0;
}

// Time Complexity: O(N*2)
// Space Complexity: O(N*2) + O(N)