#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    int maxSide = 0;

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (matrix[i][j] == '1')
        {
          if (i == 0 || j == 0)
          {
            dp[i][j] = 1;
          }
          else
          {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
          }
          maxSide = max(maxSide, dp[i][j]);
        }
      }
    }

    return maxSide * maxSide;
  }
};

int main()
{
  Solution sol;

  vector<vector<char>> matrix1 = {
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'}};
  cout << "Output for matrix1: " << sol.maximalSquare(matrix1) << endl; // Output: 4

  vector<vector<char>> matrix2 = {
      {'0', '1'},
      {'1', '0'}};
  cout << "Output for matrix2: " << sol.maximalSquare(matrix2) << endl; // Output: 1

  vector<vector<char>> matrix3 = {
      {'0'}};
  cout << "Output for matrix3: " << sol.maximalSquare(matrix3) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
