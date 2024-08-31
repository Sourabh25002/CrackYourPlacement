#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int maxDistance(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    // Add all land cells to the queue and set their distance to 0
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 1)
        {
          q.push({i, j});
          dist[i][j] = 0;
        }
      }
    }

    // Check for no land or no water case
    if (q.empty() || q.size() == n * n)
      return -1;

    // Direction vectors for moving in 4 directions (up, down, left, right)
    vector<int> directions = {-1, 0, 1, 0, -1};

    // BFS to calculate minimum distance from land cells
    while (!q.empty())
    {
      auto [x, y] = q.front();
      q.pop();

      for (int d = 0; d < 4; d++)
      {
        int nx = x + directions[d];
        int ny = y + directions[d + 1];

        if (nx >= 0 && ny >= 0 && nx < n && ny < n && dist[nx][ny] == INT_MAX)
        {
          dist[nx][ny] = dist[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    // Find the maximum distance
    int maxDist = 0;
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (grid[i][j] == 0)
        {
          maxDist = max(maxDist, dist[i][j]);
        }
      }
    }

    return maxDist;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> grid1 = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};
  // Example 2
  vector<vector<int>> grid2 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 0}};

  int result1 = sol.maxDistance(grid1);
  int result2 = sol.maxDistance(grid2);

  cout << "Example 1: " << result1 << endl; // Output: 2
  cout << "Example 2: " << result2 << endl; // Output: 4

  return 0;
}

/*
Time Complexity: O(n^2), where n is the grid size. Each cell is processed once.
Space Complexity: O(n^2) for the distance matrix and queue.
*/
