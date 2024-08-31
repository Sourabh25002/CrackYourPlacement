#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numDecodings(string s)
  {
    if (s.empty() || s[0] == '0')
      return 0;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = s[0] == '0' ? 0 : 1;

    for (int i = 2; i <= n; ++i)
    {
      int oneDigit = stoi(s.substr(i - 1, 1));
      int twoDigits = stoi(s.substr(i - 2, 2));

      if (oneDigit >= 1 && oneDigit <= 9)
      {
        dp[i] += dp[i - 1];
      }
      if (twoDigits >= 10 && twoDigits <= 26)
      {
        dp[i] += dp[i - 2];
      }
    }

    return dp[n];
  }
};

int main()
{
  Solution sol;

  string s1 = "12";
  cout << "Output for s1: " << sol.numDecodings(s1) << endl; // Output: 2

  string s2 = "226";
  cout << "Output for s2: " << sol.numDecodings(s2) << endl; // Output: 3

  string s3 = "06";
  cout << "Output for s3: " << sol.numDecodings(s3) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
