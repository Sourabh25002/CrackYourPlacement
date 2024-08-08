#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void gameOfLife(vector<vector<int>> &board)
  {
    int m = board.size(), n = board[0].size();
    vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
    vector<pair<int, int>> toOne, toZero;

    // Traverse each cell in the board
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        int liveNeighbors = 0;
        // Count live neighbors
        for (int k = 0; k < 8; k++)
        {
          int row = i + directions[k].first;
          int col = j + directions[k].second;
          if (row >= 0 && col >= 0 && row < m && col < n && board[row][col] == 1)
          {
            liveNeighbors++;
          }
        }
        // Apply the rules to determine which cells will change
        if (board[i][j] == 1)
        {
          if (liveNeighbors < 2 || liveNeighbors > 3)
          {
            toZero.push_back({i, j});
          }
        }
        else
        {
          if (liveNeighbors == 3)
          {
            toOne.push_back({i, j});
          }
        }
      }
    }

    // Update the board with the new state
    for (auto cell : toZero)
    {
      board[cell.first][cell.second] = 0;
    }
    for (auto cell : toOne)
    {
      board[cell.first][cell.second] = 1;
    }
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> board1 = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  sol.gameOfLife(board1);
  for (auto row : board1)
  {
    for (int cell : row)
    {
      cout << cell << " ";
    }
    cout << endl;
  }
  cout << endl;

  // Example 2
  vector<vector<int>> board2 = {{1, 1}, {1, 0}};
  sol.gameOfLife(board2);
  for (auto row : board2)
  {
    for (int cell : row)
    {
      cout << cell << " ";
    }
    cout << endl;
  }

  return 0;
}

// Time Complexity: O(m * n * 8) ≈ O(m * n)
// Space Complexity: O(m * n)
