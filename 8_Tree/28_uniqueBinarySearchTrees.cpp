#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numTrees(int n)
  {
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // Base case: There's one empty tree

    for (int i = 1; i <= n; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        dp[i] += dp[j] * dp[i - 1 - j];
      }
    }

    return dp[n];
  }
};

int main()
{
  Solution solution;
  int n = 3; // Example input
  int result = solution.numTrees(n);
  cout << "Number of unique BSTs with " << n << " nodes: " << result << endl;
  return 0;
}

/*
Time Complexity: O(n^2) where n is the number of nodes.
Space Complexity: O(n) for the dynamic programming table.
*/
