#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int numIslands(vector<vector<char>> &grid)
  {
    int m = grid.size();    // number of rows
    int n = grid[0].size(); // number of columns
    int count = 0;          // counter for number of islands

    // loop through every cell in the grid
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == '1')
        {                  // if cell contains land
          count++;         // increment island count
          dfs(grid, i, j); // start DFS from this cell
        }
      }
    }

    return count; // return number of islands
  }

  // DFS algorithm to explore neighboring cells
  void dfs(vector<vector<char>> &grid, int i, int j)
  {
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
    {
      // if cell is out of bounds or contains water, return
      return;
    }

    grid[i][j] = '0'; // mark cell as visited

    // recursively explore neighboring cells in all four directions
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
};

int main()
{
  Solution solution;

  // Example 1
  vector<vector<char>> grid1 = {
      {'1', '1', '1', '1', '0'},
      {'1', '1', '0', '1', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '0', '0', '0'}};
  cout << solution.numIslands(grid1) << endl; // Output: 1

  // Example 2
  vector<vector<char>> grid2 = {
      {'1', '1', '0', '0', '0'},
      {'1', '1', '0', '0', '0'},
      {'0', '0', '1', '0', '0'},
      {'0', '0', '0', '1', '1'}};
  cout << solution.numIslands(grid2) << endl; // Output: 3

  return 0;
}

/*
Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/
