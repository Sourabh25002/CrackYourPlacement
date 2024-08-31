#include <bits/stdc++.h>
using namespace std;

// Helper function to convert board state to string representation
vector<string> createBoard(const vector<int> &board)
{
  int n = board.size();
  vector<string> result(n, string(n, '.'));
  for (int i = 0; i < n; ++i)
  {
    result[i][board[i]] = 'Q';
  }
  return result;
}

// Recursive function to solve the N-Queens problem
void backtrack(int row, vector<int> &board, vector<vector<string>> &solutions, vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
{
  int n = board.size();
  if (row == n)
  {
    solutions.push_back(createBoard(board));
    return;
  }
  for (int col = 0; col < n; ++col)
  {
    if (!cols[col] && !diag1[row - col + n - 1] && !diag2[row + col])
    {
      board[row] = col;
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true;
      backtrack(row + 1, board, solutions, cols, diag1, diag2);
      cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;
    }
  }
}

vector<vector<string>> solveNQueens(int n)
{
  vector<vector<string>> solutions;
  vector<int> board(n, -1);             // Board to store queen positions
  vector<bool> cols(n, false);          // Columns where queens are placed
  vector<bool> diag1(2 * n - 1, false); // Diagonals where queens are placed
  vector<bool> diag2(2 * n - 1, false); // Diagonals where queens are placed
  backtrack(0, board, solutions, cols, diag1, diag2);
  return solutions;
}

int main()
{
  int n;
  cin >> n;
  vector<vector<string>> result = solveNQueens(n);
  for (const auto &solution : result)
  {
    for (const auto &row : solution)
    {
      cout << row << "\n";
    }
    cout << "\n";
  }
  return 0;
}

/*
Time Complexity: O(N!), where N is the size of the board. This is due to the number of permutations and checks for valid solutions.
Space Complexity: O(N^2), where N is the size of the board. This accounts for storing the board and solution states.
*/
