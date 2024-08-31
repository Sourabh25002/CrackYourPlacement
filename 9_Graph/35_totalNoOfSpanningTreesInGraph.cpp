#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;                                      // Maximum number of vertices
vector<vector<int>> adjMatrix(MAXN, vector<int>(MAXN, 0)); // Adjacency matrix
int n;                                                     // Number of vertices

// Function to calculate the cofactor of a matrix
int cofactor(vector<vector<int>> &matrix, int p, int q, int n)
{
  vector<vector<int>> temp(n - 1, vector<int>(n - 1));
  int r = 0, c = 0;

  for (int i = 0; i < n; ++i)
  {
    if (i == p)
      continue;
    c = 0;
    for (int j = 0; j < n; ++j)
    {
      if (j == q)
        continue;
      temp[r][c++] = matrix[i][j];
    }
    r++;
  }

  int det = 0;
  // Calculate the determinant of the (n-1)x(n-1) matrix
  for (int i = 0; i < n - 1; ++i)
  {
    int prod1 = 1, prod2 = 1;
    for (int j = 0; j < n - 1; ++j)
    {
      prod1 *= temp[j][j];
      prod2 *= temp[j][n - 2 - j];
    }
    det += prod1 - prod2;
  }

  return det;
}

// Function to compute the number of spanning trees
int numberOfSpanningTrees()
{
  vector<vector<int>> laplacian(n, vector<int>(n));

  // STEP 2: Create Laplacian Matrix
  for (int i = 0; i < n; ++i)
  {
    int degree = 0;
    for (int j = 0; j < n; ++j)
    {
      if (adjMatrix[i][j])
      {
        degree++;
      }
    }
    laplacian[i][i] = degree;
    for (int j = 0; j < n; ++j)
    {
      if (i != j)
      {
        laplacian[i][j] = -adjMatrix[i][j];
      }
    }
  }

  // Compute cofactor of the matrix
  return cofactor(laplacian, 0, 0, n);
}

int main()
{
  cout << "Enter the number of vertices: ";
  cin >> n;

  cout << "Enter the adjacency matrix:\n";
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> adjMatrix[i][j];
    }
  }

  int result = numberOfSpanningTrees();
  cout << "Number of spanning trees: " << result << endl;

  return 0;
}

/*
Time Complexity: O(n^3), due to the matrix determinant calculation which involves O(n^3) operations.
Space Complexity: O(n^2), for storing the adjacency matrix and the Laplacian matrix.
*/
