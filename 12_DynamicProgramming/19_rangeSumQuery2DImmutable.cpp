#include <bits/stdc++.h>
using namespace std;

class NumMatrix
{
public:
  NumMatrix(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    prefixSum.assign(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2)
  {
    return prefixSum[row2 + 1][col2 + 1] - prefixSum[row1][col2 + 1] - prefixSum[row2 + 1][col1] + prefixSum[row1][col1];
  }

private:
  vector<vector<int>> prefixSum;
};

int main()
{
  // Example 1
  vector<vector<int>> matrix = {
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}};
  NumMatrix numMatrix(matrix);
  cout << "sumRegion(2, 1, 4, 3): " << numMatrix.sumRegion(2, 1, 4, 3) << endl; // Output: 8
  cout << "sumRegion(1, 1, 2, 2): " << numMatrix.sumRegion(1, 1, 2, 2) << endl; // Output: 11
  cout << "sumRegion(1, 2, 2, 4): " << numMatrix.sumRegion(1, 2, 2, 4) << endl; // Output: 12

  return 0;
}

/*
Time Complexity: O(m * n) for initialization, O(1) for sumRegion queries
Space Complexity: O(m * n) for the prefixSum matrix
*/
