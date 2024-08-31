#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findMaxForm(vector<string> &strs, int m, int n)
  {
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (const string &s : strs)
    {
      int zeros = count(s.begin(), s.end(), '0');
      int ones = s.size() - zeros;

      for (int i = m; i >= zeros; --i)
      {
        for (int j = n; j >= ones; --j)
        {
          dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
        }
      }
    }

    return dp[m][n];
  }
};

int main()
{
  Solution sol;
  vector<string> strs1 = {"10", "0001", "111001", "1", "0"};
  int m1 = 5, n1 = 3;
  cout << "Largest subset size for strs1: " << sol.findMaxForm(strs1, m1, n1) << endl; // Output: 4

  vector<string> strs2 = {"10", "0", "1"};
  int m2 = 1, n2 = 1;
  cout << "Largest subset size for strs2: " << sol.findMaxForm(strs2, m2, n2) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(m * n * len(strs))
Space Complexity: O(m * n)
*/
