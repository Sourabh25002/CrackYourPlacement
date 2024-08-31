#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int countSquares(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int count = 0;

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (matrix[i][j] == 1)
        {
          if (i == 0 || j == 0)
          {
            dp[i][j] = 1;
          }
          else
          {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          }
          count += dp[i][j];
        }
      }
    }

    return count;
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> matrix1 = {
      {0, 1, 1, 1},
      {1, 1, 1, 1},
      {0, 1, 1, 1}};
  cout << "Output for matrix1: " << sol.countSquares(matrix1) << endl; // Output: 15

  vector<vector<int>> matrix2 = {
      {1, 0, 1},
      {1, 1, 0},
      {1, 1, 0}};
  cout << "Output for matrix2: " << sol.countSquares(matrix2) << endl; // Output: 7

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
