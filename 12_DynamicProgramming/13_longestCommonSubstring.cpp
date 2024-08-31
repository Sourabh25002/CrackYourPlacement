#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestCommonSubstring(string str1, string str2)
  {
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLength = 0;

    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        if (str1[i - 1] == str2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1] + 1;
          maxLength = max(maxLength, dp[i][j]);
        }
      }
    }

    return maxLength;
  }
};

int main()
{
  Solution sol;

  string str1 = "ABCDGH";
  string str2 = "ACDGHR";
  cout << "Output for str1 and str2: " << sol.longestCommonSubstring(str1, str2) << endl; // Output: 4

  string str3 = "ABC";
  string str4 = "ACB";
  cout << "Output for str3 and str4: " << sol.longestCommonSubstring(str3, str4) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n*m)
Space Complexity: O(n*m)
*/
