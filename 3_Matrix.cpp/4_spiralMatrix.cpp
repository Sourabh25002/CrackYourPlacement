#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
  vector<int> ans;
  if (matrix.empty())
    return ans;

  int n = matrix.size();
  int m = matrix[0].size();

  int top = 0, bottom = n - 1, left = 0, right = m - 1;

  while (top <= bottom && left <= right)
  {
    // Traverse from left to right
    for (int i = left; i <= right; ++i)
    {
      ans.push_back(matrix[top][i]);
    }
    top++;

    // Traverse from top to bottom
    for (int i = top; i <= bottom; ++i)
    {
      ans.push_back(matrix[i][right]);
    }
    right--;

    // Traverse from right to left
    if (top <= bottom)
    {
      for (int i = right; i >= left; --i)
      {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    // Traverse from bottom to top
    if (left <= right)
    {
      for (int i = bottom; i >= top; --i)
      {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return ans;
}

int main()
{
  int m, n;
  cout << "Input number of rows: ";
  cin >> m;
  cout << "Input number of columns: ";
  cin >> n;

  vector<vector<int>> matrix(m, vector<int>(n));

  cout << "Input matrix elements:" << endl;
  for (int i = 0; i < m; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> matrix[i][j];
    }
  }

  vector<int> result = spiralOrder(matrix);

  cout << "Spiral order:" << endl;
  for (int num : result)
  {
    cout << num << ' ';
  }
  cout << endl;

  return 0;
}

/*
Time Complexity: O(M * N), where M is the number of rows and N is the number of columns in the matrix.
Space Complexity: O(M * N) for storing the result.
*/
