#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int uniquePathsIII(vector<vector<int>> &grid)
  {
    int m = grid.size();
    int n = grid[0].size();
    int startRow, startCol, endRow, endCol, emptyCount = 0;

    // Find start, end positions and count empty cells
    for (int i = 0; i < m; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == 1)
        {
          startRow = i;
          startCol = j;
        }
        else if (grid[i][j] == 2)
        {
          endRow = i;
          endCol = j;
        }
        if (grid[i][j] != -1)
        {
          ++emptyCount;
        }
      }
    }

    // Backtracking function
    function<int(int, int, int)> backtrack = [&](int row, int col, int count) -> int
    {
      if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] < 0)
      {
        return 0;
      }
      if (row == endRow && col == endCol)
      {
        return count == emptyCount ? 1 : 0;
      }

      int temp = grid[row][col];
      grid[row][col] = -1; // Mark as visited
      int paths = backtrack(row + 1, col, count + 1) +
                  backtrack(row - 1, col, count + 1) +
                  backtrack(row, col + 1, count + 1) +
                  backtrack(row, col - 1, count + 1);
      grid[row][col] = temp; // Unmark
      return paths;
    };

    return backtrack(startRow, startCol, 1);
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> grid1 = {
      {1, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 2, -1}};
  cout << sol.uniquePathsIII(grid1) << endl; // Output: 2

  vector<vector<int>> grid2 = {
      {1, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 2}};
  cout << sol.uniquePathsIII(grid2) << endl; // Output: 4

  vector<vector<int>> grid3 = {
      {0, 1},
      {2, 0}};
  cout << sol.uniquePathsIII(grid3) << endl; // Output: 0

  return 0;
}

/*
Time Complexity: O(4^N), where N is the number of empty cells. The algorithm explores each possible path from the start cell to the end cell.
Space Complexity: O(N), where N is the number of empty cells. This includes the space used by the recursion stack.
*/
