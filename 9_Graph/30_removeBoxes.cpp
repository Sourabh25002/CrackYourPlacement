#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int removeBoxes(vector<int> &boxes)
  {
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

    function<int(int, int, int)> dfs = [&](int l, int r, int k) -> int
    {
      if (l > r)
        return 0;
      if (dp[l][r][k] != -1)
        return dp[l][r][k];

      // Remove the boxes from l to r with k extra boxes
      int result = (k + 1) * (k + 1) + dfs(l + 1, r, 0);
      for (int i = l + 1; i <= r; ++i)
      {
        if (boxes[i] == boxes[l])
        {
          result = max(result, dfs(l + 1, i - 1, 0) + dfs(i, r, k + 1));
        }
      }

      return dp[l][r][k] = result;
    };

    return dfs(0, n - 1, 0);
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<int> boxes1 = {1, 3, 2, 2, 2, 3, 4, 3, 1};
  cout << sol.removeBoxes(boxes1) << endl; // Output: 23

  // Example 2
  vector<int> boxes2 = {1, 1, 1};
  cout << sol.removeBoxes(boxes2) << endl; // Output: 9

  // Example 3
  vector<int> boxes3 = {1};
  cout << sol.removeBoxes(boxes3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n^3), where n is the length of the boxes array. This is due to the recursive calls and memoization.
Space Complexity: O(n^3), for the memoization table dp.
*/
