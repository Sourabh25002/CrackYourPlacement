#include <bits/stdc++.h>
using namespace std;

class MazeSolver
{
public:
  vector<vector<int>> maze;
  int n;
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  MazeSolver(vector<vector<int>> m) : maze(m), n(m.size()) {}

  bool isValid(int x, int y, vector<vector<bool>> &visited)
  {
    return x >= 0 && x < n && y >= 0 && y < n && !visited[x][y];
  }

  void findPaths(int x, int y, vector<vector<bool>> &visited, vector<pair<int, int>> &path)
  {
    if (x == n / 2 && y == n / 2)
    {
      path.push_back({x, y});
      printPath(path);
      path.pop_back();
      return;
    }

    visited[x][y] = true;
    path.push_back({x, y});

    int step = maze[x][y];
    for (auto dir : directions)
    {
      int newX = x + dir.first * step;
      int newY = y + dir.second * step;
      if (isValid(newX, newY, visited))
      {
        findPaths(newX, newY, visited, path);
      }
    }

    path.pop_back();
    visited[x][y] = false;
  }

  void printPath(vector<pair<int, int>> &path)
  {
    for (auto p : path)
    {
      cout << "(" << p.first << ", " << p.second << ") -> ";
    }
    cout << "MID" << endl;
  }

  void solve()
  {
    vector<pair<int, int>> corners = {{0, 0}, {0, n - 1}, {n - 1, 0}, {n - 1, n - 1}};
    for (auto corner : corners)
    {
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      vector<pair<int, int>> path;
      findPaths(corner.first, corner.second, visited, path);
    }
  }
};

int main()
{
  vector<vector<int>> maze = {
      {3, 5, 4, 4, 7, 3, 4, 6, 3},
      {6, 7, 5, 6, 6, 2, 6, 6, 2},
      {3, 3, 4, 3, 2, 5, 4, 7, 2},
      {6, 5, 5, 1, 2, 3, 6, 5, 6},
      {3, 3, 4, 3, 0, 1, 4, 3, 4},
      {3, 5, 4, 3, 2, 2, 3, 3, 5},
      {3, 5, 4, 3, 2, 6, 4, 4, 3},
      {3, 5, 1, 3, 7, 5, 3, 6, 4},
      {6, 2, 4, 3, 4, 5, 4, 5, 1}};

  MazeSolver solver(maze);
  solver.solve();

  return 0;
}

/*
Time Complexity: O(4^(n^2)), where n is the size of the maze. The algorithm explores all possible paths from each corner, leading to an exponential time complexity.
Space Complexity: O(n^2), due to the space needed for the visited matrix and recursion stack.
*/
