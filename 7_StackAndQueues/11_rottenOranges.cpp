#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to find minimum time required to rot all oranges.
  int orangesRotting(vector<vector<int>> &grid)
  {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;
    int vis[n][m];

    // Initialize the queue with all the rotten oranges and mark them as visited
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 2)
        {
          q.push({{i, j}, 0});
          vis[i][j] = 2;
        }
        else
        {
          vis[i][j] = 0;
        }
      }
    }

    int tm = 0;
    int drow[] = {-1, 0, +1, 0};
    int dcol[] = {0, +1, 0, -1};

    // Process the queue using BFS
    while (!q.empty())
    {
      int r = q.front().first.first;
      int c = q.front().first.second;
      int t = q.front().second;
      q.pop();

      tm = max(tm, t);

      for (int i = 0; i < 4; i++)
      {
        int nrow = r + drow[i];
        int ncol = c + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
        {
          q.push({{nrow, ncol}, t + 1});
          vis[nrow][ncol] = 2;
        }
      }
    }

    // Check if there are any fresh oranges left
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (vis[i][j] != 2 && grid[i][j] == 1)
        {
          return -1; // If any fresh orange is left, return -1
        }
      }
    }

    return tm; // Return the minimum time
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> grid1 = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};
  cout << "Example 1 Output: " << sol.orangesRotting(grid1) << endl;

  // Example 2
  vector<vector<int>> grid2 = {{2, 2, 0, 1}};
  cout << "Example 2 Output: " << sol.orangesRotting(grid2) << endl;

  return 0;
}

/*
Time Complexity: O(n*m) where n is the number of rows and m is the number of columns in the grid.
This is because each cell is processed at most once.

Space Complexity: O(n*m) for the queue and the visited array used in the BFS.
*/
