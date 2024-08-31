#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q)
  {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1)
      return;

    grid[i][j] = 2; // Mark the cell as part of the first island
    q.push({i, j});

    dfs(i + 1, j, grid, q);
    dfs(i - 1, j, grid, q);
    dfs(i, j + 1, grid, q);
    dfs(i, j - 1, grid, q);
  }

  int shortestBridge(vector<vector<int>> &grid)
  {
    int n = grid.size();
    queue<pair<int, int>> q;
    bool found = false;

    // Find the first island and use DFS to mark all its cells
    for (int i = 0; i < n && !found; i++)
    {
      for (int j = 0; j < n && !found; j++)
      {
        if (grid[i][j] == 1)
        {
          dfs(i, j, grid, q);
          found = true;
        }
      }
    }

    // Use BFS to expand the first island until we reach the second island
    int steps = 0;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty())
    {
      int size = q.size();
      while (size--)
      {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions)
        {
          int nx = x + dx;
          int ny = y + dy;

          if (nx >= 0 && ny >= 0 && nx < n && ny < n)
          {
            if (grid[nx][ny] == 1)
            {
              return steps; // We've reached the second island
            }
            if (grid[nx][ny] == 0)
            {
              grid[nx][ny] = 2; // Mark as visited
              q.push({nx, ny});
            }
          }
        }
      }
      steps++;
    }

    return -1; // Should never reach here
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> grid1 = {{0, 1}, {1, 0}};
  vector<vector<int>> grid2 = {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}};
  vector<vector<int>> grid3 = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};

  cout << sol.shortestBridge(grid1) << endl; // Output: 1
  cout << sol.shortestBridge(grid2) << endl; // Output: 2
  cout << sol.shortestBridge(grid3) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n^2), where n is the length of the grid.
Space Complexity: O(n^2), for the DFS and BFS queues.
*/
