#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int longestIncreasingPath(vector<vector<int>> &matrix)
  {
    if (matrix.empty() || matrix[0].empty())
      return 0;

    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));
    int longestPath = 0;

    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        longestPath = max(longestPath, dfs(matrix, memo, i, j));
      }
    }

    return longestPath;
  }

private:
  vector<int> directions = {0, 1, 0, -1, 0}; // Right, Down, Left, Up

  int dfs(const vector<vector<int>> &matrix, vector<vector<int>> &memo, int x, int y)
  {
    if (memo[x][y] != -1)
      return memo[x][y];

    int m = matrix.size();
    int n = matrix[0].size();
    int maxLength = 1; // The cell itself is the minimum path length

    for (int d = 0; d < 4; ++d)
    {
      int newX = x + directions[d];
      int newY = y + directions[d + 1];

      if (newX >= 0 && newX < m && newY >= 0 && newY < n && matrix[newX][newY] > matrix[x][y])
      {
        maxLength = max(maxLength, 1 + dfs(matrix, memo, newX, newY));
      }
    }

    memo[x][y] = maxLength;
    return maxLength;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> matrix1 = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
  cout << sol.longestIncreasingPath(matrix1) << endl; // Output: 4

  // Example 2
  vector<vector<int>> matrix2 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
  cout << sol.longestIncreasingPath(matrix2) << endl; // Output: 4

  // Example 3
  vector<vector<int>> matrix3 = {{1}};
  cout << sol.longestIncreasingPath(matrix3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(m * n), where m is the number of rows and n is the number of columns. Each cell is visited once.
Space Complexity: O(m * n), for the memoization table.
*/
