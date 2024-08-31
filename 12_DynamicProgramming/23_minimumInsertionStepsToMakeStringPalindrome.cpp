#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minInsertions(string s)
  {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int length = 2; length <= n; ++length)
    {
      for (int i = 0; i <= n - length; ++i)
      {
        int j = i + length - 1;
        if (s[i] == s[j])
        {
          dp[i][j] = dp[i + 1][j - 1];
        }
        else
        {
          dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  Solution sol;

  // Example 1
  string s1 = "zzazz";
  cout << "Output for s1: " << sol.minInsertions(s1) << endl; // Output: 0

  // Example 2
  string s2 = "mbadm";
  cout << "Output for s2: " << sol.minInsertions(s2) << endl; // Output: 2

  // Example 3
  string s3 = "leetcode";
  cout << "Output for s3: " << sol.minInsertions(s3) << endl; // Output: 5

  return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the string.
Space Complexity: O(n^2), due to the DP table used to store intermediate results.
*/
