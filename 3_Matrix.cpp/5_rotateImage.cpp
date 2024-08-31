#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &matrix)
{
  int n = matrix.size();

  // Transpose the matrix
  for (int i = 0; i < n; ++i)
  {
    for (int j = i; j < n; ++j)
    {
      swap(matrix[i][j], matrix[j][i]);
    }
  }

  // Reverse each row
  for (int i = 0; i < n; ++i)
  {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main()
{
  int n;
  cout << "Input the size of matrix (n): ";
  cin >> n;

  vector<vector<int>> matrix(n, vector<int>(n));

  cout << "Input matrix elements:" << endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  rotate(matrix);

  cout << "Rotated matrix:" << endl;
  for (const auto &row : matrix)
  {
    for (int num : row)
    {
      cout << num << ' ';
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(N^2), where N is the number of rows or columns in the matrix.
Space Complexity: O(1) as the rotation is done in-place.
*/
