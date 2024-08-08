#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
};

int main()
{
  Solution sol;

  // Example test cases
  vector<vector<int>> matrix1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  vector<int> result1 = sol.spiralOrder(matrix1);
  cout << "Spiral order of matrix1: ";
  for (int num : result1)
  {
    cout << num << " ";
  }
  cout << endl;

  vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  vector<int> result2 = sol.spiralOrder(matrix2);
  cout << "Spiral order of matrix2: ";
  for (int num : result2)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}

// Time Complexity: O(m * n)
// Space Complexity: O(m * n)