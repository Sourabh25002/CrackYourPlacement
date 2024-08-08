#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool dfs(int idx, int i, int j, vector<vector<char>> &mat, const string &word)
  {
    // Check if we have found the whole word
    if (idx == word.size())
      return true;

    int n = mat.size();
    int m = mat[0].size();

    // Check for out-of-bounds or mismatch
    if (i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != word[idx])
      return false;

    char ch = mat[i][j];
    // Mark the cell as visited
    mat[i][j] = '#';

    // Explore all four possible directions
    bool up = dfs(idx + 1, i - 1, j, mat, word);
    bool down = dfs(idx + 1, i + 1, j, mat, word);
    bool left = dfs(idx + 1, i, j - 1, mat, word);
    bool right = dfs(idx + 1, i, j + 1, mat, word);

    // Restore the cell to its original state
    mat[i][j] = ch;

    // Return true if any direction returns true
    return up || down || left || right;
  }

  bool exist(vector<vector<char>> &board, const string &word)
  {
    int n = board.size();
    int m = board[0].size();

    // Try to find the starting point for the word
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < m; ++j)
      {
        if (board[i][j] == word[0])
        {
          if (dfs(0, i, j, board, word))
            return true;
        }
      }
    }

    return false;
  }
};

int main()
{
  Solution sol;

  // Example test cases
  vector<vector<char>> board1 = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};
  string word1 = "ABCCED";
  cout << "Exist for board1 and word1: " << (sol.exist(board1, word1) ? "true" : "false") << endl;

  vector<vector<char>> board2 = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};
  string word2 = "SEE";
  cout << "Exist for board2 and word2: " << (sol.exist(board2, word2) ? "true" : "false") << endl;

  vector<vector<char>> board3 = {
      {'A', 'B', 'C', 'E'},
      {'S', 'F', 'C', 'S'},
      {'A', 'D', 'E', 'E'}};
  string word3 = "ABCB";
  cout << "Exist for board3 and word3: " << (sol.exist(board3, word3) ? "true" : "false") << endl;

  return 0;
}

// Time Complexity: O(m * n * 4^l)
// Space Complexity: O(m * n)