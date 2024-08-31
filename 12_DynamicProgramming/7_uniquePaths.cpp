#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int uniquePaths(int m, int n)
  {
    vector<vector<int>> dp(m, vector<int>(n, 1));

    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};

int main()
{
  Solution sol;

  int m1 = 3, n1 = 7;
  cout << "Output for m = 3, n = 7: " << sol.uniquePaths(m1, n1) << endl; // Output: 28

  int m2 = 3, n2 = 2;
  cout << "Output for m = 3, n = 2: " << sol.uniquePaths(m2, n2) << endl; // Output: 3

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
