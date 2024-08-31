#include <bits/stdc++.h>
using namespace std;

int maxAreaRectangularSubMatrix(vector<vector<int>> &mat)
{
  int rows = mat.size();
  int cols = mat[0].size();
  int maxArea = 0;

  for (int left = 0; left < cols; ++left)
  {
    vector<int> temp(rows, 0);
    for (int right = left; right < cols; ++right)
    {
      for (int i = 0; i < rows; ++i)
      {
        temp[i] += (mat[i][right] == 0 ? -1 : 1);
      }

      unordered_map<int, int> prefixSum;
      prefixSum[0] = -1;
      int currentSum = 0;

      for (int i = 0; i < rows; ++i)
      {
        currentSum += temp[i];
        if (prefixSum.find(currentSum) != prefixSum.end())
        {
          int width = right - left + 1;
          int height = i - prefixSum[currentSum];
          maxArea = max(maxArea, width * height);
        }
        else
        {
          prefixSum[currentSum] = i;
        }
      }
    }
  }

  return maxArea;
}

int main()
{
  vector<vector<int>> mat1 = {
      {0, 0, 1, 1},
      {0, 1, 1, 0},
      {1, 1, 1, 0},
      {1, 0, 0, 1}};
  cout << "Max Area for mat1: " << maxAreaRectangularSubMatrix(mat1) << " sq. units" << endl;

  vector<vector<int>> mat2 = {
      {0, 0, 1, 1},
      {0, 1, 1, 1}};
  cout << "Max Area for mat2: " << maxAreaRectangularSubMatrix(mat2) << " sq. units" << endl;

  return 0;
}

/*
Time Complexity: O(n^3), where n is the maximum of the number of rows and columns.
Space Complexity: O(n^2), due to the space required for the temporary array and the hash map.
*/
