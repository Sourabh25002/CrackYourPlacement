#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int minPathSum(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();

    // Initialize the first row
    for (int j = 1; j < n; ++j)
    {
      grid[0][j] += grid[0][j - 1];
    }

    // Initialize the first column
    for (int i = 1; i < m; ++i)
    {
      grid[i][0] += grid[i - 1][0];
    }

    // Fill the rest of the grid
    for (int i = 1; i < m; ++i)
    {
      for (int j = 1; j < n; ++j)
      {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }

    return grid[m - 1][n - 1];
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> grid1 = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  cout << "Output for grid1: " << sol.minPathSum(grid1) << endl; // Output: 7

  vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}};
  cout << "Output for grid2: " << sol.minPathSum(grid2) << endl; // Output: 12

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(1) - We are modifying the input grid in-place
*/
