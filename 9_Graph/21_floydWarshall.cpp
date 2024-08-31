#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void floydWarshall(vector<vector<int>> &matrix)
  {
    int n = matrix.size();

    // Replace -1 with infinity for easier handling
    const int INF = INT_MAX / 2;
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (matrix[i][j] == -1 && i != j)
        {
          matrix[i][j] = INF;
        }
      }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k)
    {
      for (int i = 0; i < n; ++i)
      {
        for (int j = 0; j < n; ++j)
        {
          if (matrix[i][k] < INF && matrix[k][j] < INF)
          {
            matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
          }
        }
      }
    }

    // Replace INF back to -1
    for (int i = 0; i < n; ++i)
    {
      for (int j = 0; j < n; ++j)
      {
        if (matrix[i][j] == INF && i != j)
        {
          matrix[i][j] = -1;
        }
      }
    }
  }
};

int main()
{
  Solution sol;

  // Example 1
  vector<vector<int>> matrix1 = {{0, 25}, {-1, 0}};
  sol.floydWarshall(matrix1);
  for (const auto &row : matrix1)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Example 2
  vector<vector<int>> matrix2 = {{0, 1, 43}, {1, 0, 6}, {-1, -1, 0}};
  sol.floydWarshall(matrix2);
  for (const auto &row : matrix2)
  {
    for (int val : row)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Time Complexity: O(n^3), due to the three nested loops for the Floyd-Warshall algorithm.
Space Complexity: O(1), since the matrix is updated in-place.
*/
