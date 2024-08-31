#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<char>> &mat, int x, int y)
{
  int m = mat.size();
  int n = mat[0].size();
  if (x < 0 || x >= m || y < 0 || y >= n || mat[x][y] != 'O')
  {
    return;
  }
  mat[x][y] = 'T'; // Temporary mark
  // Explore all 4 directions
  DFS(mat, x + 1, y);
  DFS(mat, x - 1, y);
  DFS(mat, x, y + 1);
  DFS(mat, x, y - 1);
}

void replaceSurroundedO(vector<vector<char>> &mat)
{
  if (mat.empty())
    return;

  int m = mat.size();
  int n = mat[0].size();

  // Perform DFS for 'O's on the border and mark them as 'T'
  for (int i = 0; i < m; ++i)
  {
    if (mat[i][0] == 'O')
      DFS(mat, i, 0);
    if (mat[i][n - 1] == 'O')
      DFS(mat, i, n - 1);
  }

  for (int j = 0; j < n; ++j)
  {
    if (mat[0][j] == 'O')
      DFS(mat, 0, j);
    if (mat[m - 1][j] == 'O')
      DFS(mat, m - 1, j);
  }

  // Replace 'O' with 'X' and 'T' with 'O'
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      if (mat[i][j] == 'O')
        mat[i][j] = 'X';
      if (mat[i][j] == 'T')
        mat[i][j] = 'O';
    }
  }
}

int main()
{
  int m, n;
  cout << "Input number of rows: ";
  cin >> m;
  cout << "Input number of columns: ";
  cin >> n;

  vector<vector<char>> mat(m, vector<char>(n));

  cout << "Input matrix elements (O or X):" << endl;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> mat[i][j];
    }
  }

  replaceSurroundedO(mat);

  cout << "Output matrix:" << endl;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(M * N), where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(M * N) for the recursion stack in the worst case.
*/
