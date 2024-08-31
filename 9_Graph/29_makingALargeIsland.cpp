#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int largestIsland(vector<vector<int>> &grid)
  {
    int n = grid.size();
    vector<vector<int>> island(n, vector<int>(n, 0));
    unordered_map<int, int> islandSize;
    int islandId = 2; // Start from 2 because 0 and 1 are already used

    // Direction vectors for 4-directional movement
    vector<int> directions = {0, 1, 0, -1, 0};

    // Function to perform DFS and mark islands
    function<void(int, int, int)> dfs = [&](int x, int y, int id)
    {
      island[x][y] = id;
      islandSize[id]++;
      for (int d = 0; d < 4; ++d)
      {
        int newX = x + directions[d];
        int newY = y + directions[d + 1];
        if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 1 && island[newX][newY] == 0)
        {
          dfs(newX, newY, id);
        }
      }
    };

    // First, mark all the islands and calculate their sizes
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == 1 && island[i][j] == 0)
        {
          dfs(i, j, islandId++);
        }
      }
    }

    int maxIslandSize = 0;

    // Check each cell if it's 0, change it to 1 and calculate the potential island size
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (grid[i][j] == 0)
        {
          unordered_set<int> seenIslands;
          int currentSize = 1; // Changing this 0 to 1
          for (int d = 0; d < 4; ++d)
          {
            int newX = i + directions[d];
            int newY = j + directions[d + 1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n && island[newX][newY] > 1 && seenIslands.find(island[newX][newY]) == seenIslands.end())
            {
              currentSize += islandSize[island[newX][newY]];
              seenIslands.insert(island[newX][newY]);
            }
          }
          maxIslandSize = max(maxIslandSize, currentSize);
        }
      }
    }

    // If no 0 was changed, return the size of the largest existing island
    int largestExistingIsland = 0;
    for (const auto &entry : islandSize)
    {
      largestExistingIsland = max(largestExistingIsland, entry.second);
    }
    return max(maxIslandSize, largestExistingIsland);
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> grid1 = {{1, 0}, {0, 1}};
  cout << sol.largestIsland(grid1) << endl; // Output: 3

  // Example 2
  vector<vector<int>> grid2 = {{1, 1}, {1, 0}};
  cout << sol.largestIsland(grid2) << endl; // Output: 4

  // Example 3
  vector<vector<int>> grid3 = {{1, 1}, {1, 1}};
  cout << sol.largestIsland(grid3) << endl; // Output: 4

  return 0;
}

/*
Time Complexity: O(n^2), where n is the size of the grid. We perform DFS on each cell and check each 0 cell once.
Space Complexity: O(n^2), for the island matrix and the islandSize map.
*/
