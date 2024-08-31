#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int prime = 1e9 + 7;

  int subsequenceCounting(string &s1, string &s2, int n, int m)
  {
    // Create a 2D DP array to store the count of distinct subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Initialize the first row: empty string s2 can be matched with any non-empty s1 in one way
    for (int i = 0; i <= n; i++)
    {
      dp[i][0] = 1;
    }

    // Initialize the first column: s1 can't match any non-empty s2
    for (int i = 1; i <= m; i++)
    {
      dp[0][i] = 0;
    }

    // Fill in the DP array
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          // If the characters match, we have two options:
          // 1. Match the current characters and move diagonally (dp[i-1][j-1])
          // 2. Leave the current character in s1 and match s2 with the previous characters (dp[i-1][j])
          dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % prime;
        }
        else
        {
          // If the characters don't match, we can only leave the current character in s1
          dp[i][j] = dp[i - 1][j];
        }
      }
    }

    // The value at dp[n][m] contains the count of distinct subsequences
    return dp[n][m];
  }

  int numDistinct(string s1, string s2)
  {
    return subsequenceCounting(s1, s2, s1.size(), s2.size());
  }
};

int main()
{
  Solution sol;

  string s1 = "rabbbit";
  string s2 = "rabbit";
  cout << "Example 1:" << endl;
  cout << "Output: " << sol.numDistinct(s1, s2) << endl;

  string s1_2 = "babgbag";
  string s2_2 = "bag";
  cout << "Example 2:" << endl;
  cout << "Output: " << sol.numDistinct(s1_2, s2_2) << endl;

  return 0;
}

/*
Time Complexity: O(n * m), where n is the length of s1 and m is the length of s2.
Space Complexity: O(n * m), where n is the length of s1 and m is the length of s2.
*/
