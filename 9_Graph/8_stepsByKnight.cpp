#include <bits/stdc++.h>
using namespace std;

struct Cell
{
  int x, y, dist;
  Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
};

bool isInside(int x, int y, int N)
{
  return (x >= 1 && x <= N && y >= 1 && y <= N);
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
  int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

  vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

  queue<Cell> q;
  q.push(Cell(KnightPos[0], KnightPos[1], 0));
  visited[KnightPos[0]][KnightPos[1]] = true;

  while (!q.empty())
  {
    Cell t = q.front();
    q.pop();

    if (t.x == TargetPos[0] && t.y == TargetPos[1])
    {
      return t.dist;
    }

    for (int i = 0; i < 8; i++)
    {
      int x = t.x + dx[i];
      int y = t.y + dy[i];

      if (isInside(x, y, N) && !visited[x][y])
      {
        visited[x][y] = true;
        q.push(Cell(x, y, t.dist + 1));
      }
    }
  }

  return -1;
}

int main()
{
  int N = 6;
  vector<int> knightPos = {4, 5};
  vector<int> targetPos = {1, 1};
  cout << minStepToReachTarget(knightPos, targetPos, N) << endl; // Output: 3

  return 0;
}

/*
Time Complexity: O(N^2)
Space Complexity: O(N^2)
*/
