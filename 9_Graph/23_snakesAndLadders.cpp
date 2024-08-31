#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int snakesAndLadders(vector<vector<int>> &board)
  {
    int n = board.size();
    vector<int> moves(n * n + 1, -1);
    queue<int> q;
    q.push(1);
    moves[1] = 0;

    while (!q.empty())
    {
      int curr = q.front();
      q.pop();
      int step = moves[curr];

      for (int i = 1; i <= 6; ++i)
      {
        int next = curr + i;
        if (next > n * n)
          break;

        int r = (next - 1) / n;
        int c = (next - 1) % n;
        if (r % 2 == 1)
          c = n - 1 - c;

        if (board[n - 1 - r][c] != -1)
        {
          next = board[n - 1 - r][c];
        }

        if (moves[next] == -1)
        {
          moves[next] = step + 1;
          if (next == n * n)
            return moves[next];
          q.push(next);
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> board1 = {
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 35, -1, -1, 13, -1},
      {-1, -1, -1, -1, -1, -1},
      {-1, 15, -1, -1, -1, -1}};
  cout << sol.snakesAndLadders(board1) << endl; // Output: 4

  // Example 2
  vector<vector<int>> board2 = {
      {-1, -1},
      {-1, 3}};
  cout << sol.snakesAndLadders(board2) << endl; // Output: 1

  return 0;
}

/*
Time Complexity: O(n^2), where n is the size of the board. We traverse each square up to 6 times.
Space Complexity: O(n^2), due to the storage required for the board and the moves vector.
*/
