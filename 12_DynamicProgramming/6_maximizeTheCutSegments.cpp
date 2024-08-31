#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximizeCuts(int n, int x, int y, int z)
  {
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 0; i <= n; ++i)
    {
      if (dp[i] != -1)
      {
        if (i + x <= n)
          dp[i + x] = max(dp[i + x], dp[i] + 1);
        if (i + y <= n)
          dp[i + y] = max(dp[i + y], dp[i] + 1);
        if (i + z <= n)
          dp[i + z] = max(dp[i + z], dp[i] + 1);
      }
    }

    return max(dp[n], 0);
  }
};

int main()
{
  Solution sol;

  int n1 = 4, x1 = 2, y1 = 1, z1 = 1;
  cout << "Output for n = 4, x = 2, y = 1, z = 1: " << sol.maximizeCuts(n1, x1, y1, z1) << endl; // Output: 4

  int n2 = 5, x2 = 5, y2 = 3, z2 = 2;
  cout << "Output for n = 5, x = 5, y = 3, z = 2: " << sol.maximizeCuts(n2, x2, y2, z2) << endl; // Output: 2

  return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
