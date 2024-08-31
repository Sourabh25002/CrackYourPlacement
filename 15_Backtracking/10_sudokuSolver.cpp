#include <bits/stdc++.h>
using namespace std;

// Function to check if a number can be placed in a cell
bool isValid(vector<vector<char>> &board, int row, int col, char num)
{
  for (int i = 0; i < 9; ++i)
  {
    if (board[row][i] == num || board[i][col] == num ||
        board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
    {
      return false;
    }
  }
  return true;
}

// Recursive backtracking function to solve Sudoku
bool solve(vector<vector<char>> &board)
{
  for (int row = 0; row < 9; ++row)
  {
    for (int col = 0; col < 9; ++col)
    {
      if (board[row][col] == '.')
      {
        for (char num = '1'; num <= '9'; ++num)
        {
          if (isValid(board, row, col, num))
          {
            board[row][col] = num;
            if (solve(board))
            {
              return true;
            }
            board[row][col] = '.'; // Backtrack
          }
        }
        return false; // Trigger backtracking
      }
    }
  }
  return true; // Sudoku is solved
}

// Function to solve the Sudoku puzzle
void solveSudoku(vector<vector<char>> &board)
{
  solve(board);
}

int main()
{
  vector<vector<char>> board = {
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

  solveSudoku(board);

  for (const auto &row : board)
  {
    for (const auto &cell : row)
    {
      cout << cell << ' ';
    }
    cout << '\n';
  }

  return 0;
}

/*
Time Complexity: O(9^(N^2)), where N is the size of the board. In the worst case, we try every possible number at every empty cell.
Space Complexity: O(N^2), where N is the size of the board. This accounts for storing the board and recursion stack.
*/
