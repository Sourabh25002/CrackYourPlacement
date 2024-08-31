#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countPalindromicSubsequences(string s)
  {
    const int MOD = 1e9 + 7;
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // dp[i][j] will hold the number of different palindromic subsequences in s[i:j+1]
    for (int len = 1; len <= n; ++len)
    {
      for (int i = 0; i + len - 1 < n; ++i)
      {
        int j = i + len - 1;
        if (i == j)
        {
          dp[i][j] = 1; // Single character is always a palindrome
        }
        else if (s[i] == s[j])
        {
          int low = i + 1, high = j - 1;
          while (low <= high && s[low] != s[i])
            ++low;
          while (low <= high && s[high] != s[j])
            --high;
          if (low > high)
          {
            dp[i][j] = dp[i + 1][j - 1] * 2 + 2; // No same character between i and j
          }
          else if (low == high)
          {
            dp[i][j] = dp[i + 1][j - 1] * 2 + 1; // Only one same character between i and j
          }
          else
          {
            dp[i][j] = dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1]; // Subtract common palindromes
          }
        }
        else
        {
          dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
        }
        dp[i][j] = (dp[i][j] + MOD) % MOD; // Ensure non-negative result
      }
    }

    return dp[0][n - 1];
  }
};

int main()
{
  Solution sol;

  string s1 = "bccb";
  cout << "Count of different palindromic subsequences (Example 1): " << sol.countPalindromicSubsequences(s1) << endl; // Output: 6

  string s2 = "abcdabcdabcdabcdabcdabcdabcdabcddcbadcbadcbadcbadcbadcbadcbadcba";
  cout << "Count of different palindromic subsequences (Example 2): " << sol.countPalindromicSubsequences(s2) << endl; // Output: 104860361

  return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the string. This is due to the nested loops filling the dp table.
Space Complexity: O(n^2), due to the dp table used to store intermediate results.
*/
