#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void findPaths(int i, int j, vector<vector<int>> &mat, int n, vector<string> &ans, string move, vector<vector<int>> &visited, int di[], int dj[])
  {
    if (i == n - 1 && j == n - 1)
    {
      ans.push_back(move);
      return;
    }

    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] && mat[nexti][nextj] == 1)
      {
        visited[i][j] = 1;
        findPaths(nexti, nextj, mat, n, ans, move + dir[ind], visited, di, dj);
        visited[i][j] = 0;
      }
    }
  }

public:
  vector<string> findPath(vector<vector<int>> &mat, int n)
  {
    vector<string> ans;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    int di[] = {1, 0, 0, -1}; // Down, Left, Right, Up directions
    int dj[] = {0, -1, 1, 0};
    if (mat[0][0] == 1)
      findPaths(0, 0, mat, n, ans, "", visited, di, dj);
    return ans;
  }
};

int main()
{
  Solution solution;

  // Example 1
  vector<vector<int>> mat1 = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};
  int n1 = 4;
  vector<string> result1 = solution.findPath(mat1, n1);
  if (result1.empty())
    cout << "-1";
  else
  {
    for (string path : result1)
    {
      cout << path << " ";
    }
  }
  cout << endl;

  // Example 2
  vector<vector<int>> mat2 = {
      {1, 0},
      {1, 0}};
  int n2 = 2;
  vector<string> result2 = solution.findPath(mat2, n2);
  if (result2.empty())
    cout << "-1";
  else
  {
    for (string path : result2)
    {
      cout << path << " ";
    }
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(3^(n^2))
Space Complexity: O(l * x), where l = length of the path, x = number of paths
*/
