#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int superEggDrop(int k, int n)
  {
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

    for (int m = 1; m <= n; ++m)
    {
      for (int eggs = 1; eggs <= k; ++eggs)
      {
        dp[eggs][m] = dp[eggs - 1][m - 1] + dp[eggs][m - 1] + 1;
        if (dp[eggs][m] >= n)
        {
          return m;
        }
      }
    }

    return n;
  }
};

int main()
{
  Solution sol;

  int k1 = 1, n1 = 2;
  cout << "Minimum moves (Example 1): " << sol.superEggDrop(k1, n1) << endl; // Output: 2

  int k2 = 2, n2 = 6;
  cout << "Minimum moves (Example 2): " << sol.superEggDrop(k2, n2) << endl; // Output: 3

  int k3 = 3, n3 = 14;
  cout << "Minimum moves (Example 3): " << sol.superEggDrop(k3, n3) << endl; // Output: 4

  return 0;
}

/*
Time Complexity: O(k * n), where k is the number of eggs and n is the number of floors.
Space Complexity: O(k * n), due to the DP table used to store results of subproblems.
*/
