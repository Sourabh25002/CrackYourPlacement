#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &grid, int i, int j)
{
  // Boundary conditions and checking if the cell is water or already visited
  if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
  {
    return;
  }

  // Mark the current cell as visited
  grid[i][j] = '0';

  // Check all 8 directions
  DFS(grid, i + 1, j);     // Down
  DFS(grid, i - 1, j);     // Up
  DFS(grid, i, j + 1);     // Right
  DFS(grid, i, j - 1);     // Left
  DFS(grid, i + 1, j + 1); // Diagonal down-right
  DFS(grid, i - 1, j - 1); // Diagonal up-left
  DFS(grid, i + 1, j - 1); // Diagonal down-left
  DFS(grid, i - 1, j + 1); // Diagonal up-right
}

int numIslands(vector<vector<char>> &grid)
{
  if (grid.empty())
    return 0;

  int numRows = grid.size();
  int numCols = grid[0].size();
  int count = 0;

  for (int i = 0; i < numRows; ++i)
  {
    for (int j = 0; j < numCols; ++j)
    {
      if (grid[i][j] == '1')
      {
        // Start a DFS search to mark all connected '1's
        DFS(grid, i, j);
        ++count;
      }
    }
  }

  return count;
}

int main()
{
  int rows, cols;
  cout << "Input number of rows: ";
  cin >> rows;
  cout << "Input number of columns: ";
  cin >> cols;

  vector<vector<char>> grid(rows, vector<char>(cols));

  cout << "Input matrix elements (0 or 1):" << endl;
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      cin >> grid[i][j];
    }
  }

  cout << "Output: " << numIslands(grid) << endl;

  return 0;
}

/*
Time Complexity: O(rows * cols), where rows is the number of rows and cols is the number of columns in the grid.
Space Complexity: O(rows * cols) for the recursion stack in the worst case.
*/
